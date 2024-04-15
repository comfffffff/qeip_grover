module weight_random_number_generator (
     clk,
     rstnn,
     random_num,
     weight,
     weight_stb,

     out,
     out_stb
);

///////////////////////////////////////////////////////////////////////////
/////////////////////////// parameters ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

parameter NUM_QUBIT = 4;
parameter WEIGHT_WIDTH = 32;

localparam NUM_WEIGHT = 2**NUM_QUBIT;
localparam NUM_WEIGHT_BIT = NUM_WEIGHT * WEIGHT_WIDTH;
localparam NUM_OUTPUT_BIT = NUM_QUBIT + 1; // to include -1 value, 
localparam NUM_SINGLE_ACC_WEIGHT_BIT = WEIGHT_WIDTH * 2;
localparam NUM_ACC_WEIGHT_BIT = NUM_WEIGHT * NUM_SINGLE_ACC_WEIGHT_BIT;



// states for FSM
parameter IDLE =        3'b000;
parameter H_STAGE =     3'b001;
parameter L_STAGE =     3'b010;
parameter ACCUMULATE =  3'b100; 
parameter MEASURE =     3'b101;


///////////////////////////////////////////////////////////////////////////
/////////////////////////// Input & Output ////////////////////////////////
///////////////////////////////////////////////////////////////////////////

input wire clk;
input wire rstnn;
input wire[WEIGHT_WIDTH-1:0] random_num;
input wire[NUM_WEIGHT_BIT-1:0] weight;
input wire weight_stb;

output reg[NUM_OUTPUT_BIT-1:0] out;
output reg out_stb;

///////////////////////////////////////////////////////////////////////////
/////////////////////////// Signal declaration ////////////////////////////
///////////////////////////////////////////////////////////////////////////

reg[NUM_WEIGHT_BIT-1:0] acc_weight;
reg[2:0] fsm_state;
reg[2:0] next_fsm_state;
reg[NUM_QUBIT-1:0] h;
reg[NUM_QUBIT-1:0] acc_stage;
integer j;

///////////////////////////////////////////////////////////////////////////
/////////////////////// FSM for process of Measurement ////////////////////
///////////////////////////////////////////////////////////////////////////

always@ (posedge clk, negedge rstnn)
begin
    if(rstnn == 0)  fsm_state <= IDLE;
    else            fsm_state <= next_fsm_state;
end


always @(*) 
begin
    next_fsm_state = IDLE;
    case(fsm_state)
        IDLE:
        begin
            if(weight_stb == 1 && out_stb == 0) next_fsm_state = H_STAGE;
            else                                next_fsm_state = IDLE;
        end

        H_STAGE: 
        begin
            next_fsm_state = L_STAGE;
        end

        L_STAGE:
        begin
            next_fsm_state = ACCUMULATE;
        end

        ACCUMULATE:
        begin
            if(acc_stage == NUM_QUBIT - 1) next_fsm_state = MEASURE;
            else                           next_fsm_state = ACCUMULATE;
        end

        MEASURE:
        begin
            next_fsm_state = IDLE;
        end

    endcase
end

///////////////////////////////////////////////////////////////////////////
////////////////////// Behavior of Measurement  ///////////////////////////
///////////////////////////////////////////////////////////////////////////

always @(posedge clk or negedge rstnn) 
begin
    if(rstnn == 0)
    begin
        h <= 0;
        acc_stage <= 0;
        acc_weight <= 0;
        out <= {(NUM_OUTPUT_BIT){1'b1}};
        out_stb <= 0;
    end
    else
    begin
        case(fsm_state)
            IDLE:
            begin
                h <= 0;
                acc_stage <= 0;
                acc_weight <= 0;
                out <= 0;
                out_stb <= 0;
            end

            H_STAGE: // approximation applied
            begin
                for(j=0; j<NUM_WEIGHT; j=j+1)
                begin
                    if( $signed(weight[WEIGHT_WIDTH*(j+1)-1 -: WEIGHT_WIDTH]) > $signed(32'h20000000)) // if amp is larger than 0.5 in fixed expression
                    begin
                        acc_weight[WEIGHT_WIDTH*(j+1)-1 -: WEIGHT_WIDTH] <= (weight[WEIGHT_WIDTH*(j+1)-1 -: WEIGHT_WIDTH] - 32'h20000000) << 1;
                        h <= j;
                    end
                end
            end

            L_STAGE: // approximation applied
            begin
                if(acc_weight[WEIGHT_WIDTH*(h+1)-1] == 0) // if acc_weight[h] is possitive
                begin
                    for(j=0; j<NUM_WEIGHT; j=j+1)
                    begin
                        if(j != h) 
                        begin
                            acc_weight[WEIGHT_WIDTH*(j+1)-1 -: WEIGHT_WIDTH] <=
                                ((32'h40000000 - acc_weight[WEIGHT_WIDTH*(h+1)-1 -: WEIGHT_WIDTH]) >> NUM_QUBIT) + ((32'h40000000 - acc_weight[WEIGHT_WIDTH*(h+1)-1 -: WEIGHT_WIDTH]) >> (NUM_QUBIT << 1));// if positive
                        end
                    end
                end
                else // if acc_weight[h] is negative
                begin
                    for(j=0; j<NUM_WEIGHT; j=j+1)
                    begin
                        if(j != h) 
                        begin
                            acc_weight[WEIGHT_WIDTH*(j+1)-1 -: WEIGHT_WIDTH] <= 
                                ((32'h40000000 + acc_weight[WEIGHT_WIDTH*(h+1)-1 -: WEIGHT_WIDTH]) >> NUM_QUBIT) + ((32'h40000000 + acc_weight[WEIGHT_WIDTH*(h+1)-1 -: WEIGHT_WIDTH]) >> (NUM_QUBIT << 1)); // if negative
                        end
                    end
                end
            end

            ACCUMULATE: // parallelism applied
            begin
                /*
                for(j = 1<<(acc_stage); j<NUM_WEIGHT; j=j+1)
                begin
                    acc_weight[WEIGHT_WIDTH*(j+1)-1 -: WEIGHT_WIDTH] <= 
                        acc_weight[WEIGHT_WIDTH*(j+1)-1 -: WEIGHT_WIDTH] + acc_weight[WEIGHT_WIDTH*(j+1-(1<<acc_stage))-1 -: WEIGHT_WIDTH];
                        $display("j = %0d\n",j);
                end
                */
                for(j = 1; j<(NUM_WEIGHT - acc_stage); j=j+1)
                begin
                    acc_weight[WEIGHT_WIDTH*(j+1+(1<<acc_stage))-1 -: WEIGHT_WIDTH] <= 
                        acc_weight[WEIGHT_WIDTH*(j+1+(1<<acc_stage))-1 -: WEIGHT_WIDTH] + acc_weight[WEIGHT_WIDTH*(j+1)-1 -: WEIGHT_WIDTH];
                        $display("j = %0d\n",j);
                end
                $display("acc_stage = %0d\n\n", acc_stage);
                acc_stage <= acc_stage + 1;
                
            end

            MEASURE:
            begin
                out <= 0;
                for (j = 1; j < NUM_WEIGHT; j = j + 1) 
                begin
                    if ( /* out > (NUM_QUBIT-1) && // out is not refreshed before completing the cycle */
                        ({2'b00 ,random_num[29:0]} < acc_weight[WEIGHT_WIDTH*(j+1)-1 -: WEIGHT_WIDTH]) &&
                        ({2'b00 ,random_num[29:0]} >= acc_weight[WEIGHT_WIDTH*j-1 -: WEIGHT_WIDTH]) ) 
                    begin
                        out <= j;
                        // break; // NOT SYNTHESIZABLE LINE
                    end
                end
                out_stb <= 1;
            end
        endcase
    end

end

endmodule
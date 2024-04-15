module weight_random_number_generator (
     clk,
     rstnn,
     random_num,
     weight,
     weight_stb,

     out,
     out_stb
);

parameter NUM_QUBIT = 4;
parameter WEIGHT_WIDTH = 32;

localparam NUM_WEIGHT = 2**NUM_QUBIT;
localparam NUM_WEIGHT_BIT = NUM_WEIGHT * WEIGHT_WIDTH;
localparam NUM_OUTPUT_BIT = NUM_QUBIT;
localparam NUM_SINGLE_ACC_WEIGHT_BIT = WEIGHT_WIDTH * 2;
localparam NUM_ACC_WEIGHT_BIT = NUM_WEIGHT * NUM_SINGLE_ACC_WEIGHT_BIT;

input wire clk;
input wire rstnn;
input wire[WEIGHT_WIDTH-1:0] random_num;
input wire[NUM_WEIGHT_BIT-1:0] weight;
input wire weight_stb;

output reg[NUM_OUTPUT_BIT-1:0] out;
output reg out_stb;

reg[NUM_ACC_WEIGHT_BIT-1:0] acc_weight;

integer j;

always@ (*)
begin
    acc_weight = {(NUM_ACC_WEIGHT_BIT){0}};
    if(weight_stb)
    begin
        for(j=0; j<NUM_WEIGHT; j=j+1)
        begin
            acc_weight[NUM_SINGLE_ACC_WEIGHT_BIT*(j+1)-1 -: NUM_SINGLE_ACC_WEIGHT_BIT] 
                = $signed(weight[WEIGHT_WIDTH*(j+1)-1 -: WEIGHT_WIDTH]) ** 2;
        end

        for(j=1; j<NUM_WEIGHT; j=j+1)
        begin
            acc_weight[NUM_SINGLE_ACC_WEIGHT_BIT*(j+1)-1 -: NUM_SINGLE_ACC_WEIGHT_BIT] 
                = acc_weight[NUM_SINGLE_ACC_WEIGHT_BIT*(j+1)-1 -: NUM_SINGLE_ACC_WEIGHT_BIT]
                + acc_weight[NUM_SINGLE_ACC_WEIGHT_BIT*j-1 -: NUM_SINGLE_ACC_WEIGHT_BIT];
        end
    end
end

always @(posedge clk or negedge rstnn) 
begin
    if (!rstnn) 
    begin
        out <= 0;
        out_stb <= 0;
    end
    else if(weight_stb)
    begin
        for (j = 0; j < NUM_WEIGHT; j = j + 1) 
        begin
            // 63-bit 1-2-58 fixed point #(acc_weight) are reduced to 32-bit 1-1-30 fixed point #(random_num)
            if ({2'b00 ,random_num[29:0]} < {acc_weight[NUM_SINGLE_ACC_WEIGHT_BIT*(j+1)-1], acc_weight[NUM_SINGLE_ACC_WEIGHT_BIT*(j+1)-4], acc_weight[NUM_SINGLE_ACC_WEIGHT_BIT*(j+1)-5 -: 30]})    
            begin
                out <= j;  
                break;
            end
        end
        out_stb <= 1;
    end
    else
    begin
        out_stb <= 0;
    end
end




endmodule
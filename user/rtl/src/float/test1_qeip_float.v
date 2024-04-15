/*`include "ervp_global.vh"

module TEST1_APB
(
    clk,
    rstnn,

    rpsel,
    rpenable,
    rpaddr,
    rpwrite,
    rpwdata,
    rprdata,
    rpready,
    rpslverr
);

///////////////////////////////////////////////////////////////////////////
/////////////////////////// parameters ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

parameter BW_DATA = 1;
parameter BW_ADDR = 1;

parameter NUM_QUBIT = 4; // #qubits up to 10

localparam NUM_STATE = 2**NUM_QUBIT;
localparam NUM_TABLE = NUM_QUBIT-$clog2(BW_DATA)>0 ?
    2**(NUM_QUBIT-$clog2(BW_DATA)) : 1;
localparam BW_TABLE = BW_DATA;
localparam NUM_TABLE_BIT = BW_DATA * NUM_TABLE;


// Must modify MAX_TRIAL to be dependent to NUM_QUBIT
// MAX_TRIAL = (pi) * (2**(NUM_QUBIT/2)) / 4
localparam MAX_TRIAL = 4;

// states for FSM
parameter IDLE =            6'b000_000;
parameter INIT =            6'b000_001;
parameter SET_T =           6'b000_010;
parameter ORACLE =          6'b000_100;
parameter DIFFUSE_mac =     6'b000_101;
parameter DIFFUSE_sub =     6'b000_110;
parameter VERIFY =          6'b001_000;



///////////////////////////////////////////////////////////////////////////
/////////////////////////// Input & Output ////////////////////////////////
///////////////////////////////////////////////////////////////////////////


input wire clk;
input wire rstnn;

input wire rpsel;
input wire rpenable;
input wire[BW_ADDR-1:0] rpaddr;
input wire rpwrite;
input wire[BW_DATA-1:0] rpwdata;
output reg[BW_DATA-1:0] rprdata;
output reg rpready;
output reg rpslverr;

///////////////////////////////////////////////////////////////////////////
/////////////////////////// Signal declaration ////////////////////////////
///////////////////////////////////////////////////////////////////////////

// APB related signals

wire[7:0] addr_offset = rpaddr[7:0];
reg is_valid_addr;

// Signals related to arithmetics


wire[BW_DATA-1:0] init_entry = (NUM_QUBIT % 2 == 0) ? 
    (32'h4000_0000 >> (NUM_QUBIT / 2)) :            // Shifting fixed point expression of sqrt(0.25)
    (32'h2D41_3CCE >> ((NUM_QUBIT - 1) / 2));       // Shifting fixed point expression of sqrt(0.5)

// amp_state in 32-bit FIXED point expression
// amp_state[31] : sign bit
// amp_state[30] : integer bit
// amp_state[29:0] : fraction bit
reg[32*NUM_STATE-1:0] amp_state; 

reg[NUM_TABLE_BIT-1:0] func_table;
reg[NUM_TABLE-1:0] func_table_we; 
reg[NUM_QUBIT-1:0] t; // arbitrary iteration time

// Signals for subroutines

wire[32+NUM_QUBIT-1:0] acc_out;
reg[32+NUM_QUBIT-1:0] acc_output;

wire[32*NUM_STATE-1:0] sub_out;

wire[NUM_QUBIT-1:0] wrng_out;
wire wrng_out_stb;
reg wrng_weight_stb;

wire[NUM_QUBIT-1:0] measure;
wire[31:0] random_num;
assign measure = wrng_out;

// Control signals

reg activate;
reg[5:0] fsm_state;
reg[5:0] next_fsm_state;
integer j;

reg[NUM_QUBIT-1:0] iteration; // # iteration of HZorHZf operation
reg[NUM_QUBIT-1:0] trial; // # trials for whole process of Grover's algorithm
reg success;
reg no_solution;

///////////////////////////////////////////////////////////////////////////
/////////////////////////// translate APB signals /////////////////////////
///////////////////////////////////////////////////////////////////////////

always@ (*)
begin
    is_valid_addr = 0;
    func_table_we = 0;
    activate = 0;

    if(rpsel == 1)
    begin  
        if(rpenable == 1)
        begin
            case(addr_offset[7:4])
            
            // access to func_table
            // #qubits up to 10
            4'h0, 4'h1:
            begin
                is_valid_addr = 1;
                func_table_we[addr_offset[3:0]] = rpwrite;
            end

            // activate grover's algorithm
            4'h4:
            begin
                if(~(addr_offset[3:0]))
                begin
                    is_valid_addr = 1;
                    activate = !(rpwrite);
                end
            end
            endcase
        end
    end
end

///////////////////////////////////////////////////////////////////////////
/////////////////////////// Set rpready signal ////////////////////////////
///////////////////////////////////////////////////////////////////////////

always@ (*)
begin
    rpready = 1;
    if(addr_offset == 8'h40 && (success || no_solution) == 0)
        rpready = 0;
end

///////////////////////////////////////////////////////////////////////////
/////////////////////////// Set func_table ////////////////////////////////
///////////////////////////////////////////////////////////////////////////

always@ (posedge clk, negedge rstnn)
begin
    if(rstnn == 0)
    begin
        for(j=0; j<NUM_STATE; j=j+1)
        begin
            func_table[j] <= 0;
        end
    end
    else 
    begin
        for(j=0; j<NUM_STATE; j=j+1)
        begin
            if(func_table_we[j])
            begin
                func_table[BW_DATA*(j+1)-1 -: BW_DATA] <= rpwdata;
            end
        end
    end
end

///////////////////////////////////////////////////////////////////////////
/////////////////////// FSM for process of Grover's algorithm /////////////
///////////////////////////////////////////////////////////////////////////

always@ (posedge clk, negedge rstnn)
begin
    if(rstnn == 0)  fsm_state <= IDLE;
    else            fsm_state <= next_fsm_state;
end

always@ (*)
begin
    next_fsm_state = IDLE;
    case(fsm_state)
        IDLE:
        begin
            if(activate && ~(success || no_solution)) 
                    next_fsm_state = INIT;
            else    next_fsm_state = IDLE;
        end

        INIT:
        begin
            next_fsm_state = SET_T;
        end

        SET_T:
        begin
            next_fsm_state = ORACLE;
        end

        ORACLE:
        begin
            next_fsm_state = DIFFUSE_mac;
        end

        DIFFUSE_mac:
        begin
            next_fsm_state = DIFFUSE_sub;
        end

        DIFFUSE_sub:
        begin
            if(iteration == t) next_fsm_state = VERIFY;
            else               next_fsm_state = ORACLE;            
        end

        VERIFY:
        begin
            next_fsm_state = VERIFY;
            if(wrng_out_stb)
            begin
                if(func_table[measure] == 1) next_fsm_state = IDLE;
                else if(trial == MAX_TRIAL)  next_fsm_state = IDLE;
                else                         next_fsm_state = INIT;
            end
        end

    endcase
end
    
///////////////////////////////////////////////////////////////////////////
/////////////////////////// Subroutine modules ////////////////////////////
///////////////////////////////////////////////////////////////////////////


random_number_generator #(
    .OUTPUT_WIDTH(32)
) rng (
    .clk(clk),
    .rstnn(rstnn),

    .random_num(random_num)
);

accumulator #(
    .DATA_WIDTH(BW_DATA)
) acc (
    .in(amp_state),
    .out(acc_out)
);

subtractor #(
    .NUM_QUBIT(NUM_QUBIT),
    .DATA_WIDTH(BW_DATA)
) sub (
    .A(acc_output),
    .B(amp_state),
  
    .out(sub_out)
);

weight_random_number_generator #(
    .NUM_QUBIT(NUM_QUBIT),
    .WEIGHT_WIDTH(BW_DATA)
) wrng (
    .clk(clk),
    .rstnn(rstnn),

    .random_num(random_num),

    .weight(amp_state),
    .weight_stb(wrng_weight_stb),
    .out(wrng_out),
    .out_stb(wrng_out_stb)
);

///////////////////////////////////////////////////////////////////////////
////////////////////// Behavior of Grover's algorithm /////////////////////
///////////////////////////////////////////////////////////////////////////

always@ (posedge clk, negedge rstnn)
begin
    if(rstnn == 0)
    begin  
        success <= 0;
        no_solution <= 0;
        iteration <= 0;
        trial <= 0;
        t <= 0;
        wrng_weight_stb <= 0;
    end
    else 
    begin
        case(fsm_state)
            IDLE:
            begin
                success <= 0;
                no_solution <= 0;
                iteration <= 0;
                trial <= 0;
                t <= 0;
                wrng_weight_stb <= 0;

            end

            INIT:
            begin
                for(j=0; j<NUM_STATE; j=j+1)
                begin
                    // pseudo expression
                    amp_state[32*(j+1)-1 -: 32] <= init_entry; 
                end

                trial <= trial + 1;
                iteration <= 0;
                
            end

            SET_T:
            begin
                // t <= (random_num % trial) + 1;
                t <= t + 1;
            end

            ORACLE:
            begin
                for(j=0; j<NUM_STATE; j=j+1)
                    if(func_table[j]) amp_state[32*(j+1)-1 -: 32] <= -amp_state[32*(j+1)-1 -: 32];
                
                iteration <= iteration + 1;
            end

            DIFFUSE_mac:
            begin
                acc_output <= acc_out >>> (NUM_QUBIT - 1);
            end

            DIFFUSE_sub:
            begin
                amp_state <= sub_out;
                if(iteration == t) wrng_weight_stb <= 1;
            end

            VERIFY:
            begin
                wrng_weight_stb <= 0;
                if(wrng_out_stb)
                begin
                    if(func_table[measure] == 1) success <= 1;
                    else if(trial == MAX_TRIAL)  no_solution <= 1;
                    //else                         trial <= trial + 1;
                end
            end

        endcase
    end
end

///////////////////////////////////////////////////////////////////////////
/////////////////////////// Set rprdata signal ////////////////////////////
///////////////////////////////////////////////////////////////////////////

always@ (*)
begin
    rprdata = 0;
    if(success) 
        rprdata = 1;
    else if(no_solution) 
        rprdata = -1;
end


///////////////////////////////////////////////////////////////////////////
/////////////////////////// rpslverr //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

always@ (posedge clk, negedge rstnn)
begin
    if(rstnn == 0)
        rpslverr <= 0;
    else if(rpsel == 1) 
    begin
        if(rpenable == 0) 
            rpslverr <= 0;
        else 
            rpslverr <= ~is_valid_addr;
    end
end
endmodule
*/
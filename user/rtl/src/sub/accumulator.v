// asynchronous module
// synchronously save output of acc to the reg

module accumulator (
    in,
    out
);

parameter NUM_QUBIT = 4;
parameter DATA_WIDTH = 32;
localparam NUM_INPUT = 2**NUM_QUBIT;
localparam NUM_INPUT_BIT = NUM_INPUT * DATA_WIDTH;
localparam NUM_OUTPUT_BIT = DATA_WIDTH + NUM_QUBIT;

input wire[NUM_INPUT_BIT-1:0] in;
output reg[NUM_OUTPUT_BIT-1:0] out;

integer j;

always@ (*)
begin
    out = {(NUM_OUTPUT_BIT){1'b0}};
    for(j=0; j<NUM_INPUT; j=j+1)
    begin
        out = out + { {(NUM_QUBIT) { in[DATA_WIDTH * (j+1) - 1] }} , in[DATA_WIDTH * (j+1) - 1 -: DATA_WIDTH]};
    end
end 
endmodule




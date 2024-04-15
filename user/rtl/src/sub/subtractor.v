// out = {A-B[32*16-1:32*15], A-B[32*15-1:32*14], ... ,A-B[32*1-1:32*0]}
// example for NUM_QUBIT=4

// asynchronous module
// synchronously save output of acc to the reg

module subtractor (
    A,
    B,
    out
);

parameter NUM_QUBIT = 4;
parameter DATA_WIDTH = 32;
localparam NUM_B_INPUT = 2**(NUM_QUBIT);
localparam NUM_B_BIT = DATA_WIDTH * NUM_B_INPUT;
localparam NUM_OUT_BIT = NUM_B_BIT;

input wire[32+NUM_QUBIT-1:0] A;
input wire[NUM_B_BIT-1:0] B;

output reg[NUM_OUT_BIT-1:0] out;

integer j;

always@ (*)
begin
    for(j=0; j<NUM_B_INPUT; j=j+1)
        out[DATA_WIDTH*(j+1)-1 -: DATA_WIDTH] = A - B[DATA_WIDTH*(j+1)-1 -: DATA_WIDTH];
end

endmodule
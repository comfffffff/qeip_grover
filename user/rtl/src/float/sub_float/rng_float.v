// LSFR PRNG

module random_number_generator (
    clk,
    rstnn,

    random_num
);

parameter OUTPUT_WIDTH = 32;

input wire clk;
input wire rstnn;
    
output reg[OUTPUT_WIDTH-1:0] random_num;

always@ (posedge clk, negedge rstnn)
begin
    if(!rstnn)
    begin
        // random_num <= {{(OUTPUT_WIDTH-1){1'b0}},1'b1};
        random_num <= 32'hF23A_27BB;
    end
    else
    begin
        random_num <= random_num << 1;
        random_num[0] <= random_num[31] ^ random_num[21] ^ random_num[1] ^ random_num[0];
    end
end

endmodule
`timescale 1ns / 1ps

module EX_MEM(
    input       clk,
    input       WB_i,
    input       W_i,
    output      WB,
    output      branch,
    output      memread,
    output      memwrite
    );

always @(posedge clk) begin
    branch=W_i[2];
    memread=W_i[1];
    memwrite=W_i[0];
    WB=WB_i;
end

endmodule

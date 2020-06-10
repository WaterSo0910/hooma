`timescale 1ns / 1ps

module MEM_WB(
    input       clk,
    input       WB,
    output      mem_to_reg,
    output      reg_write
    );

always @(posedge clk) begin
    mem_to_reg=WB[1];
    reg_write=WB[0];
end

endmodule

`timescale 1ns / 1ps

module MEM_WB(
    input       clk,
    input [1:0]  WB_i,
	 input [31:0] data_i,
	 input [31:0] addr_i,
	 input [4:0]  ins_i,
	 output reg [31:0] addr_o,
	 output reg [31:0] data_o,
	 output reg [4:0] ins_o,
    output reg    mem_2_reg,
    output reg     reg_write
    );

always @(posedge clk) begin
    mem_2_reg=WB_i[1];
    reg_write=WB_i[0];
	 data_o=data_i;
	 ins_o=ins_i;
	 addr_o=addr_i;
end

endmodule

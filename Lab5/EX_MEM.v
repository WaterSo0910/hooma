`timescale 1ns / 1ps

module EX_MEM(
    input       clk,
    input [1:0] WB_i,
    input [1:0]    M_i,
	 input		 zero_i,
    input [31:0] alu_i,
	 input [31:0] data_i,
	 input [4:0] ins_i,
	 output reg 		 zero_o,
	 output reg [31:0] alu_o,
	 output reg [31:0] data_o,
	 output reg [4:0] ins_o,
	 output  reg [1:0]  WB_o,
    output reg      memread,
    output reg      memwrite
    );

always @(posedge clk) begin
    memread=M_i[1];
    memwrite=M_i[0];
    WB_o=WB_i;
	 zero_o=zero_i;
	 alu_o=alu_i;
	 data_o=data_i;
	 ins_o=ins_i;
	 
end

endmodule

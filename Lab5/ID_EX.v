`timescale 1ns / 1ps

module ID_EX(
		input clk,
		input          ALUSrc_i,
		input          MemtoReg_i,
		input          RegWrite_i,
		input          MemRead_i,
		input          MemWrite_i,
		input  [1:0]	ALUOp_i,
		input [31:0]	pc_i,
		input [31:0]	data1_i,
		input [31:0]	data2_i,
		input [31:0]	imm_i,
		input [3:0]		ins1_i,
		input	[4:0]		ins2_i,
		input [4:0]    Rs1_addr_i,
		input [4:0]    Rs2_addr_i,
		output reg [31:0]	data1_o,
		output reg [31:0]	data2_o,
		output reg [31:0]	imm_o,
		output reg [3:0]	ins1_o,
		output reg [4:0]	ins2_o,
		output reg [31:0]  pc_o,
		output reg [1:0]   WB,
		output reg [1:0]	M,
		output reg  ALUSrc_o,
		output reg [1:0] ALUOp_o,
		output reg [4:0]    Rs1_addr_o,
		output reg [4:0]    Rs2_addr_o
	    );

always @(posedge clk) begin
	ALUSrc_o=ALUSrc_i;
	ALUOp_o=ALUOp_i;
	WB = {MemtoReg_i, RegWrite_i};
	M =	{MemRead_i, MemWrite_i};
	data1_o=data1_i;
	data2_o=data2_i;
	pc_o=pc_i;
	imm_o=imm_i;
	ins1_o=ins1_i;
	ins2_o=ins2_i;
	Rs1_addr_o=Rs1_addr_i;
	Rs2_addr_o=Rs2_addr_i;
end


endmodule

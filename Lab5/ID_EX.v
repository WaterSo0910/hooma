`timescale 1ns / 1ps

module ID_EX(
		input clk,
		input          ALUSrc_i,
		input          MemtoReg_i,
		input          RegWrite_i,
		input          MemRead_i,
		input          MemWrite_i,
		input          Branch_i,
		input  [1:0]	   ALUOp_i,
		output [1:0]   	   WB,
		output  [2:0]	   M,
		output   		ALUSrc_o,
		output			ALUOp_o
	    );

always @(posedge clk) begin
	ALUSrc_o=ALUSrc_i;
	ALUOp_o=ALUOp_i;
	WB = {MemtoReg_i, RegWrite_i};
	W =	{Branch_i, MemRead_i, MemWrite_i};
end


endmodule

/***************************************************
Student Name:Yu_Ho_Chang
Student ID: 0716046 
***************************************************/

`timescale 1ns/1ps

module ALU_Ctrl(
	input	[4-1:0]	instr,
	input	[2-1:0]	ALUOp,
	output reg	[4-1:0] ALU_Ctrl_o
	);
	
/* Write your code HERE */

	always@(*)begin
		case(ALUOp)
			2'b00:
				ALU_Ctrl_o=4'b0010;
			2'b01:
				ALU_Ctrl_o=4'b0110;
			2'b10:
				case(instr)
					4'b0000:
						ALU_Ctrl_o=4'b0010;
					4'b1000:
						ALU_Ctrl_o=4'b0110;
					4'b0111:
						ALU_Ctrl_o=4'b0000;
					4'b0110:
						ALU_Ctrl_o=4'b0001;
				endcase
		endcase
	end
endmodule
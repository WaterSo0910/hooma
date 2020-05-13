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
			2'b00://S_type
				ALU_Ctrl_o=4'b0010;
			2'b01://B_type
				if(instr[0])
					ALU_Ctrl_o=4'b1110;//bne
				else
					ALU_Ctrl_o=4'b1000;//beq	
			2'b10://R_type
				case(instr)
					4'b0000://add
						ALU_Ctrl_o=4'b0010;
					4'b1000://sub
						ALU_Ctrl_o=4'b0110;
					4'b0111://and
						ALU_Ctrl_o=4'b0000;
					4'b0110://or
						ALU_Ctrl_o=4'b0001;
					4'b0100://xor
						ALU_Ctrl_o=4'b0100;
					4'b0010://slt
						ALU_Ctrl_o=4'b0111;
					4'b0001://sll
						ALU_Ctrl_o=0011;
					4'b0100://sra
						ALU_Ctrl_o=1010;		
				endcase
			2'b11://I_type
				case(instr[3:0])
					3'b000://addi
						ALU_Ctrl_o=4'b0010;
					3'b010://slti
						ALU_Ctrl_o=4'b0111;
					3'b111://andi
						ALU_Ctrl_o=4'b0000;
					3'b110://ori
						ALU_Ctrl_o=4'b0001;
					3'b001://slli
						ALU_Ctrl_o=0011;
					3'b101://srli
						ALU_Ctrl_o=1111;		
				endcase	
		endcase
	end
endmodule
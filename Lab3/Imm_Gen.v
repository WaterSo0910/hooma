/***************************************************
Student Name:Yu_Ho_Chang
Student ID: 0716046
***************************************************/

`timescale 1ns/1ps

module Imm_Gen(
	input  [31:0] instr_i,
	output reg [31:0] Imm_Gen_o
	);

/* Write your code HERE */
	wire [6:0]  op;
	
	assign op=instr_i[6:0];
	
	always@(*)begin
		case(op)
			
			7'b0010011:
				//assign Imm_Gen_o[11:0]=instr_i[31:20];
				Imm_Gen_o[31:0]={{20{instr_i[31]}},instr_i[31:20]};
			7'b0100011:
				/*assign Imm_Gen_o[11:5]=instr_i[31:25];
				assign Imm_Gen_o[4:0]=instr_i[11:6];*/
				Imm_Gen_o[31:0]={{20{instr_i[31]}},instr_i[31:25],instr_i[11:6]};
			7'b1100011:
				//assign Imm_Gen_o[12]=instr_i[31];
				Imm_Gen_o[31:1]={{20{instr_i[31]}},instr_i[7],instr_i[30:25],instr_i[11:8]};
			default:
				Imm_Gen_o=Imm_Gen_o;
		endcase
	end
endmodule
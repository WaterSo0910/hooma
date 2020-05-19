/***************************************************
Student Name: Yu_Ho_Chang
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
			7'b1101111://J_type
				Imm_Gen_o[31:0]={{12{instr_i[31]}},instr_i[19:12],instr_i[20],instr_i[30:21]};
			7'b0010011://I_type
				Imm_Gen_o[31:0]={{20{instr_i[31]}},instr_i[31:20]};
			7'b0000011://ld
				Imm_Gen_o[31:0]={{20{instr_i[31]}},instr_i[31:20]};	
			7'b0100011://S_type
				Imm_Gen_o[31:0]={{20{instr_i[31]}},instr_i[31:25],instr_i[11:7]};
			7'b1100011://B_type
				Imm_Gen_o[31:0]={{21{instr_i[31]}},instr_i[7],instr_i[30:25],instr_i[11:8]};
			default:
				Imm_Gen_o=32'd0;
		endcase
	end
endmodule

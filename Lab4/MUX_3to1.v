/***************************************************
Student Name: Yu_Ho_Chang
Student ID: 0716046
***************************************************/

`timescale 1ns/1ps

module MUX_3to1(
	input  [31:0] data0_i,       
	input  [31:0] data1_i,
	input  [31:0] data2_i,
	input  [ 1:0] select_i,
	output reg [31:0] data_o
    );		   

/* Write your code HERE */
	always@(*)begin
		case(select_i)
			2'b00:
				data_o<=data0_i;
			2'b01:
				data_o<=data1_i;
			2'b10:
				data_o<=data2_i;
			default:
					data_o<=data_o;
		endcase
	end	
endmodule      
          
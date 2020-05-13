/***************************************************
Student Name:Yu_Ho_Chang
Student ID: 0716046
***************************************************/

`timescale 1ns/1ps

module MUX_2to1(
	input  [32-1:0] data0_i,       
	input  [32-1:0] data1_i,
	input       	select_i,
	output  reg[32-1:0] data_o
               );
			   
/* Write your code HERE */

	always@(*)begin
				//$display("select_i = %3d", select_i);
				case(select_i)
					1'b0 :
						data_o<=data0_i;
					1'b1 :
						data_o<=data1_i;	
					default :
						data_o<=data_o;
				endcase
	end					
endmodule      
          
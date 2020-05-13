/***************************************************
Student Name:Yu_Ho_Chang
Student ID: 0716046
***************************************************/
`timescale 1ns/1ps

module alu(
	input      					rst_n,         	// negative reset            (input)
	input	       [32-1:0]	src1,          	// 32 bits source 1          (input)
	input	   	 [32-1:0]	src2,      		   // 32 bits source 2          (input)
	input 	    [ 4-1:0] 	ALU_control,   	// 4 bits ALU control input  (input)
	output reg   [32-1:0]	result,        	// 32 bits result            (output)
	output reg              zero,          	// 1 bit when the output is 0, zero must be set (output)
	output reg              cout,          	// 1 bit carry out           (output)
	output reg              overflow       	// 1 bit overflow            (output)
	);

/* Write your code HERE */

reg [32:0] temp;
	
	always@(*)begin
		if(rst_n)begin
		case(ALU_control)
			4'b0000: begin
				assign temp=src1&src2;
				assign result=temp[31:0];
				assign zero=!result;
				assign cout=0;
				assign overflow=0;
			end
		
			4'b0001:begin
				assign temp=src1|src2;
				assign result=temp[31:0];
				assign zero=!result;
				assign cout=0;
				assign overflow=0;
			end
			
			4'b0010:begin
				assign temp=src1+src2;
				assign result=temp[31:0];
				assign zero=!result;
				assign cout=temp[32];
				assign overflow=(src1>0&src2>0&result<0)|(src1<0&src2<0&result>0);
			end
			
			4'b0110:begin
				assign result=src1-src2;
				assign result=temp[31:0];
				assign zero=!result;
				assign cout=temp[32];
				assign overflow=(src1<0&src2>0&result>0)|(src1>0&src2<0&result<0);
			end
			
			4'b1100:begin
				assign temp=!src1|!src2;
				assign result=temp[31:0];
				assign zero=!result;
				assign cout=0;
				assign overflow=0;
			end
			4'b1101:begin
				assign temp=!src1&!src2;
				assign result=temp[31:0];
				assign zero=!result;
				assign cout=0;
				assign overflow=0;	
			end
			4'b0111:begin
				assign temp=src1-src2;
				assign result=!temp;
				assign zero=!result;
				assign cout=0;
				assign overflow=0;
			end
		endcase
		end
	end

endmodule

/***************************************************
Student Name:Yu_Ho Chang
Student ID:0716046
***************************************************/
`timescale 1ns/1ps

module alu(
	input          rst_n,         				// negative reset            (input)
	input	     		[32-1:0]	src1,          	// 32 bits source 1          (input)
	input	     		[32-1:0]	src2,          	// 32 bits source 2          (input)
	input 	     	[4-1:0] 	ALU_control,   	// 4 bits ALU control input  (input)
	output   		[32-1:0]	result,        	// 32 bits result            (output)
	output     		zero,          				// 1 bit when the output is 0, zero must be set (output)
	output     		cout,          				// 1 bit carry out           (output)
	output     		overflow       				// 1 bit overflow            (output)
	);

/* Write your code HERE */
	
	
		wire [32-1:0]c;
		wire set, z;		
		ALU_1bit		top(src1[0]&rst_n, src2[0]&rst_n, ALU_control[2], set, ALU_control[3],
						ALU_control[2], ALU_control[1:0], result[0], c[0]);	
	
		genvar i;
		generate
			for(i=1; i<31; i =i+1)
			begin:fuck
				ALU_1bit		inner(src1[i]&rst_n, src2[i]&rst_n, c[i-1], 1'b0, ALU_control[3],
								ALU_control[2], ALU_control[1:0], result[i], c[i]);
			end
		endgenerate
		
		ALU_1bit_bottom 	bottom(src1[31]&rst_n, src2[31]&rst_n, c[30], 1'b0, ALU_control[3],
								ALU_control[2], ALU_control[1:0], result[31], set, c[31], overflow);

			or(z, result[0], result[1], result[2], result[3], result[4], result[5], result[6]
	, result[7], result[8], result[9], result[10], result[11], result[12], result[13], result[14], result[15]
	, result[16], result[17], result[18], result[19], result[20], result[21], result[22], result[23], result[24]
	, result[25], result[26], result[27], result[28], result[29], result[30], result[31]);
		assign zero=!z;
		assign cout=c[31];

endmodule

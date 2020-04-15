`timescale 1ns / 1ps
/***************************************************
Student Name: Yu_Ho Chang
Student ID: 0716046
***************************************************/
module ALU_1bit_bottom(
	input				src1,       			//1 bit source 1  (input)
	input				src2,       			//1 bit source 2  (input)
	input 			Cin,        			//1 bit carry in  (input)
	input  			less, 					//1 bit less		(input)
	input 			Ainvert,   				//1 bit A_invert  (input)
	input				Binvert,    			//1 bit B_invert  (input)
	input 	      [2-1:0] operation,  	//2 bit operation (input)
	output     		result,     			//1 bit result    (output)
	output     		set, 						//1 bit set			(output)
	output         cout,						//1 bit cout		(outout)
	output	      overflow        		//1 bit overflow  (output)
    );

	wire a, b, and_out, or_out;
	mux_2to1 	mux_2to1_a(Ainvert, src1, !src1, a);
	mux_2to1 	mux_2to1_b(Binvert, src2, !src2, b);
	and(and_out, a, b);
	or(or_out, a, b);
	full_adder 	full_adder(a, b, Cin, set, cout);
	mux_4to1 	mux_4to1(operation, and_out, or_out, set, less, result);
	xor(overflow, Cin, cout);

endmodule

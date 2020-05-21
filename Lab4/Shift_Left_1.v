/***************************************************
Student Name: 
Student ID: 
***************************************************/

`timescale 1ns/1ps

module Shift_Left_1(
    input  [31:0] data_i,
    output reg [31:0] data_o
    );

/* Write your code HERE */

	always@(*)begin
		data_o=data_i<<1;
	end
endmodule
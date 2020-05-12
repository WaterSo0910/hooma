/***************************************************
Student Name:Yu_Ho_Chang
Student ID: 0716046
***************************************************/

`timescale 1ns/1ps

module Shift_Left_1(
    input  [32-1:0] data_i,
    output [32-1:0] data_o
    );

/* Write your code HERE */

	assign data_o[31:0]={data_i[30:0],1'b0};

endmodule
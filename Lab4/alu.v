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
			case(ALU_control)
				4'b0000: begin//and
					temp=src1&src2;
					result=temp[31:0];
					zero=!result;
					cout=0;
					overflow=0;
				end
			
				4'b0001:begin//or
					temp=src1|src2;
					result=temp[31:0];
					zero=!result;
					cout=0;
					overflow=0;
				end

				4'b0010:begin//add
					temp=src1+src2;
					result=temp[31:0];
					zero=0;
					cout=temp[32];
					overflow=(src1>0&&src2>0&&result<0)||(src1<0&&src2<0&&result>0);
				end

				4'b0011:begin//sll
					temp=src1 << src2;
					result=temp[31:0];
					zero=!result;
					cout=temp[32];
					overflow=0;
				end

				4'b0100:begin//xor
					temp=src1^src2;
					result=temp[31:0];
					zero=!result;
					cout=0;
					overflow=0;
				end

				4'b0101:begin//bge
					if(src1>=src2)
						zero=1'b1;
					else
						zero=1'b0;
					temp=src1-src2;
					result=temp[31:0];
					cout=temp[32];	
					overflow=0;
				end

				4'b0110:begin//sub
					temp=src1-src2;	
					result=temp[31:0];
					zero=!result;
					cout=temp[32];
					overflow=(src1<0&&src2>0&&result>0)||(src1>0&&src2<0&&result<0);
				end

				4'b0111:begin//slt
					if(src1>src2)
						result=32'b1;
					else
						result={31'b0,1'b1};
					temp=src1-src2;
					zero=!result;
					cout=0;
					overflow=0;
				end

				4'b1000:begin//beq
					zero=~|(src1^src2);
					result=temp[31:0];
					cout=temp[32];	
					overflow=0;							
				end

				4'b1100:begin//nor
					temp=!src1&!src2;
					result=temp[31:0];
					zero=!result;
					cout=0;
					overflow=0;
				end

				4'b1001:begin//blt
					if(src1<src2)
						zero=1'b1;
					else
						zero=1'b0;
					temp=src1-src2;
					result=temp[31:0];
					cout=temp[32];	
					overflow=0;
				end

				4'b1010:begin//sra
					result=src1 >>> src2;
					zero=!result;
					cout=temp[32];
					overflow=0;
				end

				4'b1101:begin//nand
					temp=!src1|!src2;
					result=temp[31:0];
					zero=!result;
					cout=0;
					overflow=0;	
				end
				
				4'b1110:begin//bne
					zero=|(src1^src2);
					result=temp[31:0];
					cout=temp[32];
					overflow=0;
				end

				4'b1111:begin//srli
					temp=src1 >> src2;
					result=temp[31:0];
					zero=!result;
					cout=temp[32];
					overflow=0;
				end
				
				default:begin
					result=0;
					zero=0;
					cout=0;
					overflow=0;
				end
			endcase
		end
endmodule

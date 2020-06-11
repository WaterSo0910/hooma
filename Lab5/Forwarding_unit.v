`timescale 1ns / 1ps

module Forwarding_unit(
			input			RegWrite_EM,
			input       RegWrite_MW,
			input [4:0] rd_MW,
			input [4:0] rd_EM,
			input [4:0] rs1_IE,
			input [4:0] rs2_IE,
			input [4:0] rs1_ID,
			input [4:0] rs2_ID,
			output reg  [1:0] sel_1,
			output reg  [1:0] sel_2,
			output reg  sel_RS,
			output reg  sel_RT
    );



always@(*) begin
	
	sel_1=2'b00;
	sel_2=2'b00;
	sel_RS=1'b0;
	sel_RT=1'b0;
	
	if (RegWrite_EM && (rd_EM !=0) &&(rd_EM==rs1_IE)) begin
		sel_1=2'b10;
	end
	
	if ((RegWrite_MW) && (rd_MW!=0)&&(rd_MW==rs1_IE) && !((RegWrite_EM) && (rd_EM == 0) && (rd_EM==rs1_IE))) begin
		sel_1=2'b01;	
	end
	
	if (RegWrite_EM && (rd_EM !=0) &&(rd_EM==rs2_IE)) begin
		sel_2=2'b10;
	end
	
	if ((RegWrite_MW) && (rd_MW!=0) &&(rd_MW==rs2_IE)&& !((RegWrite_EM) && (rd_EM == 0) && (rd_EM==rs2_IE))) begin		
		sel_2=2'b01;
	end
	
	if((RegWrite_MW) && (rs1_ID!=0) && (rs1_ID == rd_MW)) begin
		sel_RS=1'b1;
	end
	
	if((RegWrite_MW) && (rs2_ID!=0) && (rs2_ID == rd_MW)) begin
		sel_RT=1'b1;
	end
	
	
end
endmodule

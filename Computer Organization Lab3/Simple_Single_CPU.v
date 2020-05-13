/***************************************************
Student Name:Yu_Ho_Chang
Student ID: 0716046
***************************************************/

`timescale 1ns/1ps
module Simple_Single_CPU(
	input clk_i,
	input rst_i
	);

//Internal Signals
	wire [31:0] pc_i;
	wire [31:0] pc_o;
	wire [31:0] instr;
	wire [31:0] ALUresult;
	wire RegWrite;
	wire [31:0] RSdata_o;
	wire [31:0] RTdata_o;
	wire ALUSrc;
	wire Branch;
	wire [1:0] ALUOp;
	wire pcsrc;
	wire zero;
	wire [31:0] ad1;
	wire [31:0] ad2;
	wire [31:0] imm_o;
	wire [31:0] sh;
	wire [31:0] src2;
	wire cout;
	wire over;
	wire [3:0] ALUc;
	

	assign pcsrc = Branch&zero;
	ProgramCounter PC(
			  .clk_i(clk_i),      
			 .rst_i (rst_i),     
			 .pc_i(pc_i) ,   
			 .pc_o(pc_o) 
			 );

	Instr_Memory IM(
			  .addr_i(pc_o),  
			 .instr_o(instr)    
			 );
			
	Reg_File RF(
			  .clk_i(clk_i),      
			 .rst_i(rst_i) ,     
			  .RSaddr_i(instr[19:15]) ,  
			  .RTaddr_i(instr[24:20]) ,  
			  .RDaddr_i(instr[11:7]) ,  
			  .RDdata_i(ALUresult)  , 
			  .RegWrite_i (RegWrite),
			  .RSdata_o(RSdata_o) ,  
			  .RTdata_o(RTdata_o)   
			  );
			
	Decoder Decoder(
			  .instr_i(instr), 
			.ALUSrc(ALUSrc),
			 .RegWrite(RegWrite),
			 .Branch(Branch),
			.ALUOp(ALUOp)      
			 );	

	Adder Adder1(
			  .src1_i(pc_o),     
			 .src2_i({{28{1'b0}},4'b0100}),     
			 .sum_o(ad1)    
			 );
			
	Imm_Gen ImmGen(
			.instr_i(instr),
			.Imm_Gen_o(imm_o)
			);
		
	Shift_Left_1 SL1(
			.data_i(imm_o),
			.data_o(sh)
			);
		
	MUX_2to1 Mux_ALUSrc(
			.data0_i(RTdata_o),       
			.data1_i(imm_o),
			.select_i(ALUSrc),
			.data_o(src2)
			);
				
	ALU_Ctrl ALU_Ctrl(
			.instr({instr[30],instr[14:12]}),
			.ALUOp(ALUOp),
			.ALU_Ctrl_o(ALUc)
			);
			
	Adder Adder2(
			  .src1_i(pc_o),     
			 .src2_i(sh),     
			 .sum_o(ad2)    
			 );
				
	alu alu(
			.rst_n(rst_i),
			.src1(RSdata_o),
			.src2(src2),
			.ALU_control(ALUc),
			.zero(zero),
			.result(ALUresult),
			.cout(cout),
			.overflow(over)
			);

	
	//and and1(pcsrc,Branch, zero);	
	
	MUX_2to1 Mux_PCSrc(
			.data0_i(ad1),       
			.data1_i(ad2),
			.select_i(pcsrc),
			.data_o(pc_i)
			);
			
	//always@(*)
		//$display(" pc_i = %3d, zero = %3d, branch = %3d,", pc_i,zero,Branch);		
endmodule
		  



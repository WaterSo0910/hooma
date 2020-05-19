/***************************************************
Student Name: Yu_Ho_Chang
Student ID: 0716046
***************************************************/

`timescale 1ns/1ps
module Simple_Single_CPU(
	input clk_i,
	input rst_i
	);

wire [31:0] pc_o;
wire [31:0] instr;
wire RegWrite;
wire [31:0] RSdata_o;
wire [31:0] RTdata_o;
wire [31:0] ALUresult;
wire MemRead,MemWrite;
wire [31:0] DM_o;
wire [31:0] pc_i;
wire [31:0] RDdata_i;
wire [1:0] Jump;
wire [1:0] ALUOp;
wire ALUSrc;
wire [31:0] sum_1;
wire [31:0] Imm_Gen_o;
wire [31:0] Imm;
wire [31:0] sum_2;
wire [31:0] src2;
wire [3:0] ALU_control;
wire [31:0] pc_data0;
wire [31:0] write;
wire cout,zero,overflow,sel_1,Branch;

assign sel_1=zero&Branch;

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
        .RDdata_i(RDdata_i)  , 
        .RegWrite_i (RegWrite),
        .RSdata_o(RSdata_o) ,  
        .RTdata_o(RTdata_o)   
        );		

Data_Memory Data_Memory(
		.clk_i(clk_i),
		.addr_i(ALUresult),
		.data_i(RTdata_o),
		.MemRead_i(MemRead),
		.MemWrite_i(MemWrite),
		.data_o(DM_o)
		);
		
Decoder Decoder(
        .instr_i(instr), 
		.ALUSrc(ALUSrc),
		.MemtoReg(MemtoReg),
	    .RegWrite(RegWrite),
		.MemRead(MemRead),
		.MemWrite(MemWrite),
	    .Branch(Branch),
		.ALUOp(ALUOp),
		.Jump(Jump)
	    );
		
Adder Adder1(
        .src1_i(pc_o),     
	    .src2_i(32'd4),     
	    .sum_o(sum_1)    
	    );
		
Imm_Gen ImmGen(
		.instr_i(instr),
		.Imm_Gen_o(Imm_Gen_o)
		);
	
Shift_Left_1 SL1(
		.data_i(Imm_Gen_o),
		.data_o(Imm)
		);
	
MUX_2to1 Mux_ALUSrc(
		.data0_i(RTdata_o),       
		.data1_i(Imm_Gen_o),
		.select_i(ALUSrc),
		.data_o(src2)
		);
			
ALU_Ctrl ALU_Ctrl(
		.instr({instr[30],instr[14:12]}),
		.ALUOp(ALUOp),
		.ALU_Ctrl_o(ALU_control)
		);
		
Adder Adder2(
        .src1_i(pc_o),     
	    .src2_i(Imm),     
	    .sum_o(sum_2)    
	    );
		
alu alu(
		.rst_n(rst_i),
		.src1(RSdata_o),
		.src2(src2),
		.ALU_control(ALU_control),
		.zero(zero),
		.result(ALUresult),
		.cout(cout),
		.overflow(overflow)
		);
	
MUX_2to1 Mux_PCSrc(
		.data0_i(sum_1),       
		.data1_i(sum_2),
		.select_i(sel_1),
		.data_o(pc_data0)
		);
		
MUX_2to1 Mux_MemtoReg(
		.data0_i(ALUresult),       
		.data1_i(DM_o),
		.select_i(MemtoReg),
		.data_o(write)
		);

MUX_3to1 Mux_Jump(
		.data0_i(pc_data0),
		.data1_i(Imm),
		.data2_i(RSdata_o),
		.select_i(Jump),
		.data_o(pc_i)
		);		

MUX_3to1 Mux_Write(
		.data0_i(write),
		.data1_i(sum_1),
		.data2_i(32'b0),
		.select_i(Jump),
		.data_o(RDdata_i)
		);

endmodule
		  



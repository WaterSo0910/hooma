/***************************************************
Student Name: Yu_Ho_Chang
Student ID: 0716046
***************************************************/

`timescale 1ns/1ps
module Pipeline_CPU(
	input clk_i,
	input rst_i
	);

wire [31:0] pc_o;
wire [31:0] pc_i;
wire [31:0] sum_1;
wire [31:0] instr;
//II
wire [31:0] instr_II;
wire [31:0] pc_II;
//RF
wire [31:0] RSdata_o;
wire [31:0] RTdata_o;
wire [31:0] RDdata_i;
//ImmGen
wire [31:0] Imm_Gen_o;
//IE
wire [1:0]  WB_IE;
wire [1:0]  M_IE;
wire [31:0] pc_IE;
wire [31:0] src1_IE;
wire [31:0] data2_IE;
wire [31:0] Imm_IE;
wire [3:0]  ins1_IE;
wire [4:0]  ins2_IE;
wire 			ALUSrc_IE;
wire [1:0]	ALUOp_IE;
wire [4:0]  Rs1_IE;
wire [4:0]  Rs2_IE;
//Decoder
wire RegWrite;
wire MemtoReg;
wire MemRead,MemWrite;
wire [1:0] ALUOp;
wire ALUSrc;
//EM
wire [1:0]  WB_EM;   
wire			zero_EM;
wire [31:0] alu_EM;
wire [31:0] data_EM;
wire [4:0]  ins_EM;
wire 			memread_EM;
wire			memwrite_EM;
//ALU
wire [31:0] ALUresult;
wire cout,zero,overflow;
//DM
wire [31:0] DM_o;
//MW
wire [31:0] data_MW;
wire [31:0] addr_MW;
wire [4:0]  ins_MW;
wire 			MemtoReg_MW;
wire			RegWrite_MW;
//shift
wire [31:0] Imm;
//mux1
wire [31:0] src2;
//alu_control
wire [3:0] ALU_control;
//FU
wire [1:0] sel_1_FU;
wire [1:0] sel_2_FU;
wire		  sel_RS;
wire		  sel_RT;
//MUX_3to1
wire [31:0] src1_mux;
wire [31:0] src2_mux;
//RSdata, RTdata
wire [31:0] RSdata;
wire [31:0] RTdata;

Forwarding_unit FU(
			.RegWrite_EM(WB_EM[0]),
			.RegWrite_MW(RegWrite_MW),
			.rd_MW(ins_MW),
			.rd_EM(ins_EM),
			.rs1_IE(Rs1_IE),
			.rs2_IE(Rs2_IE),
			.rs1_ID(instr_II[19:15]),
			.rs2_ID(instr_II[24:20]),
			.sel_1(sel_1_FU),
			.sel_2(sel_2_FU),
			.sel_RS(sel_RS),
			.sel_RT(sel_RT)
	);

ProgramCounter PC(
        .clk_i(clk_i),      
	    .rst_i (rst_i),     
	    .pc_i(pc_i) ,   
	    .pc_o(pc_o) 
	    );
		 		 
Adder Adder1(
        .src1_i(pc_o),     
	    .src2_i(32'd4),     
	    .sum_o(pc_i)    
	    );

Instr_Memory IM(
        .addr_i(pc_o),  
	    .instr_o(instr)    
	    );		
IF_ID II(
		.clk(clk_i),
		.instr_i(instr),
		.pc_i(pc_o),
		.pc_o(pc_II),
		.instr_o(instr_II)
		);

Reg_File RF(
        .clk_i(clk_i),      
	    .rst_i(rst_i) ,     
        .RSaddr_i(instr_II[19:15]) ,  
        .RTaddr_i(instr_II[24:20]) ,  
        .RDaddr_i(ins_MW) ,  
        .RDdata_i(RDdata_i)  , 
        .RegWrite_i (RegWrite_MW),
        .RSdata_o(RSdata_o),  
        .RTdata_o(RTdata_o)   
        );		
MUX_2to1 RSdata_mux(
			.data0_i(RSdata_o),
			.data1_i(RDdata_i),
			.select_i(sel_RS),
			.data_o(RSdata)
		);

MUX_2to1 RTdata_mux(
			.data0_i(RTdata_o),
			.data1_i(RDdata_i),
			.select_i(sel_RT),
			.data_o(RTdata)
		);
		
Decoder Decoder(
        .instr_i(instr_II), 
		.ALUSrc(ALUSrc),
		.MemtoReg(MemtoReg),
	    .RegWrite(RegWrite),
		.MemRead(MemRead),
		.MemWrite(MemWrite),
		.ALUOp(ALUOp)
	    );
		 
Imm_Gen ImmGen(
		.instr_i(instr_II),
		.Imm_Gen_o(Imm_Gen_o)
		);
		 
ID_EX IE(
		.clk(clk_i),		
		.ALUSrc_i(ALUSrc),
		.MemtoReg_i(MemtoReg),
		.RegWrite_i(RegWrite),
		.MemRead_i(MemRead),
		.MemWrite_i(MemWrite),
		.ALUOp_i(ALUOp),
		.pc_i(pc_II),
		.data1_i(RSdata),
		.data2_i(RTdata),
		.imm_i(Imm_Gen_o),
		.ins1_i({instr_II[30],instr_II[14:12]}),
		.ins2_i(instr_II[11:7]),
		.Rs1_addr_i(instr_II[19:15]),
		.Rs2_addr_i(instr_II[24:20]),
		.pc_o(pc_IE),
		.data1_o(src1_IE),
		.data2_o(data2_IE),
		.imm_o(Imm_IE),
		.ins1_o(ins1_IE),
		.ins2_o(ins2_IE),
		.WB(WB_IE),
		.M(M_IE),
		.ALUSrc_o(ALUSrc_IE),
		.ALUOp_o(ALUOp_IE),
		.Rs1_addr_o(Rs1_IE),
		.Rs2_addr_o(Rs2_IE)
		);

		
		
	
MUX_2to1 Mux_ALUSrc(
		.data0_i(data2_IE),       
		.data1_i(Imm_IE),
		.select_i(ALUSrc_IE),
		.data_o(src2)
		);
			
ALU_Ctrl ALU_Ctrl(
		.instr(ins1_IE),
		.ALUOp(ALUOp_IE),
		.ALU_Ctrl_o(ALU_control)
		);


MUX_3to1  alu_src1(
		.data0_i(src1_IE),
		.data1_i(RDdata_i),
		.data2_i(alu_EM),
		.select_i(sel_1_FU),
		.data_o(src1_mux)
		);
		
MUX_3to1  alu_src2(
		.data0_i(src2),
		.data1_i(RDdata_i),
		.data2_i(alu_EM),
		.select_i(sel_2_FU),
		.data_o(src2_mux)
		);
		
alu alu(
		.rst_n(rst_i),
		.src1(src1_mux),
		.src2(src2_mux),
		.ALU_control(ALU_control),
		.zero(zero),
		.result(ALUresult),
		.cout(cout),
		.overflow(overflow)
		);
		
EX_MEM EM(
			.clk(clk_i),
			.WB_i(WB_IE),
			.M_i(M_IE),
			.zero_i(zero),
			.alu_i(ALUresult),
			.data_i(data2_IE),
			.ins_i(ins2_IE),
			.WB_o(WB_EM),
			.zero_o(zero_EM),
			.alu_o(alu_EM),
			.data_o(data_EM),
			.ins_o(ins_EM),
			.memread(memread_EM),
			.memwrite(memwrite_EM)
		);
			
			

Data_Memory Data_Memory(
		.clk_i(clk_i),
		.addr_i(alu_EM),
		.data_i(data_EM),
		.MemRead_i(memread_EM),
		.MemWrite_i(memwrite_EM),
		.data_o(DM_o)
		);
		


MEM_WB MW(
			.clk(clk_i),
			.WB_i(WB_EM),
			.data_i(DM_o),
			.addr_i(alu_EM),
			.ins_i(ins_EM),
			.data_o(data_MW),
			.addr_o(addr_MW),
			.ins_o(ins_MW),
			.mem_2_reg(MemtoReg_MW),
			.reg_write(RegWrite_MW)
		);
		
MUX_2to1 Mux_MemtoReg(
		.data0_i(addr_MW),       
		.data1_i(data_MW),
		.select_i(MemtoReg_MW),
		.data_o(RDdata_i)
		);
	

endmodule
		  




/***************************************************
Student Name:Yu_Ho Chang
Student ID:0716046
***************************************************/
module mux_4to1(
    input [2-1:0]sel,
	 input a,
    input b,
    input c,
    input d,
    output reg z
    );

   always @ (*) begin
      case (sel)
         2'b00 : z = a;
         2'b01 : z = b;
         2'b10 : z = c;
         2'b11 : z = d;
      endcase
   end

endmodule

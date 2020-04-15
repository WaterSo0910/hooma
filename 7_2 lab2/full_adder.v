
/***************************************************
Student Name:Yu_Ho Chang
Student ID:0716046
***************************************************/
module full_adder(
    input a,
    input b,
    input c_in,
    output out,
    output c_out
    );

	wire s, c1, c2;
	xor(s, a, b);
	and(c1, a, b);
	xor(out, s, c_in);
	and(c2, s, c_in);
	or(c_out, c2, c1);

endmodule

`timescale 1ns/1ps
module M10to1(
  input I0, I1, I2, I3, I4, I5, I6, I7, I8, I9, S0, S1, S2, S3, 
  output out
	);
	wire T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14;
	not(T1, S0);
	not(T2, S1);
	not(T3, S2);
	not(T4, S3);
	and(T5, I0, T1, T2, T3, T4), (T6, I1, S0, T2, T3, T4);
	and(T7, I2, T1, S1, T3, T4), (T8, I3, S0, S1, T3, T4);
	and(T9, I4, T1, T2, S2, T4), (T10, I5, S0, T2, S2, T4);
	and(T11, I6, T1, S1, S2, T4), (T12, I7, S0, S1, S2, T4);
	and(T13, I8, T1, T2, T3, S3), (T14, I9, S0, T2, T3, S3);
	or(out, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14);

endmodule

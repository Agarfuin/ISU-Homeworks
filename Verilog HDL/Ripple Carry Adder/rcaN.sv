`timescale 1ns/100ps

module half_adder(
  input a,
  input b,
  output s,
  output cout
);
  
  assign s = a ^ b;
  assign cout = a & b;
  
endmodule

module full_adder(
  input a,
  input b,
  input cin,
  output s,
  output cout
);
  wire c1, c2, s1;
  
  half_adder ha1(a, b, s1, c1);
  half_adder ha2(s1, cin, s, c2);
  
  or o1(cout, c1, c2);
  
endmodule

module ripple_carry_adder(
  input [3:0] a,
  input [3:0] b,
  input cin,
  output [3:0] s,
  output cout
);
  wire c1, c2, c3;

  full_adder fa0(a[0], b[0], cin, s[0], c1);
  full_adder fa1(a[1], b[1], c1, s[1], c2);
  full_adder fa2(a[2], b[2], c2, s[2], c3);
  full_adder fa3(a[3], b[3], c3, s[3], cout);

endmodule
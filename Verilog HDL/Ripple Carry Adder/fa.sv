`timescale 1ns / 100ps

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
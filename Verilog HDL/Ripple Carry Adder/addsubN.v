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

module adder_subtractor(
  input [3:0] a,
  input [3:0] b,
  input cin,
  output [3:0] s,
  output cout,
  output reg ovf
);
  wire c1, c2, c3, x0, x1, x2, x3;
  always @* begin
    if((~a[3] && ~b[3] && s[3]) || (a[3] && b[3] && ~s[3]))
      ovf = 1;
    else
      ovf = 0;
  end

  xor xor0(x0, cin, b[0]);
  full_adder fa0(a[0], x0, cin, s[0], c1);
  xor xor1(x1, cin, b[1]);
  full_adder fa1(a[1], x1, c1, s[1], c2);
  xor xor2(x2, cin, b[2]);
  full_adder fa2(a[2], x2, c2, s[2], c3);
  xor xor3(x3, cin, b[3]);
  full_adder fa3(a[3], x3, c3, s[3], cout);

endmodule
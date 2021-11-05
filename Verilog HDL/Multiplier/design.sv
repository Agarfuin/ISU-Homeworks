`timescale 1ns / 100ps

module multiplier(
  input [0:1]a, 
  input [0:1]b,
  output reg [0:3]m
  );
  
  initial begin
    m = 4'b0000;
  end
  
  always @(a or b) begin
    
    if((a[0] && a[1] && b[0] && b[1]))
      m[0] <= 1'b1;
    else
      m[0] <= 1'b0;

    if((a[0] && ~a[1] && b[0]) || (a[0] && b[0] && ~b[1]))
      m[1] <= 1'b1;
    else
      m[1] <= 1'b0;

    if((a[0] && ~b[0] && b[1]) || (a[0] && ~a[1] && b[1]) || (~a[0] && a[1] && b[0]) || (a[1] && b[0] && ~b[1]))
      m[2] <= 1'b1;
    else
      m[2] <= 1'b0;

    if((a[1] && b[1]))
      m[3] <= 1'b1;
    else
      m[3] <= 1'b0;
    
  end
endmodule
`timescale 1ns / 100ps

module comparator(
  input [0:1]a, 
  input [0:1]b,
  output g,
  output e,
  output l
  );

  reg g0;
  reg e0;
  reg l0;
  
  always @(*) begin
    if((a[1] && !b[1]) || (a[1] && a[0] && !b[0]) || (a[0] && !b[1] && !b[0])) begin
      g0 = 1'b1;
      e0 = 1'b0;
      l0 = 1'b0;
    end
    
    else if((!a[1] && b[1]) || (!a[1] && !a[0] && b[0]) || (!a[0] && b[1] && b[0])) begin
      g0 = 1'b0;
      e0 = 1'b0;
      l0 = 1'b1;
    end
  
    else begin
      g0 = 1'b0;
      e0 = 1'b1;
      l0 = 1'b0;
    end
  end
  assign g = g0;
  assign e = e0;
  assign l = l0;
  
endmodule
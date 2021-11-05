`timescale 1ns / 100ps

module comparator_tb;
  reg [0:1]a = 2'b00;
  reg [0:1]b = 2'b00;
  wire g;
  wire e;
  wire l;
  
  comparator dut(
    .a(a),
    .b(b),
    .g(g),
    .e(e),
    .l(l)
  );
  
  initial begin
    $dumpfile("dump.vcd");
    $dumpvars;
    #1;
    a <= 2'b11;
    b <= 2'b01;
    $display("a: %b, b: %b, g: %b, e: %b, l: %b", a, b, g, e, l);
    #1;
    a <= 2'b00;
    b <= 2'b11;
    $display("a: %b, b: %b, g: %b, e: %b, l: %b", a, b, g, e, l);
    #1;
    a <= 2'b10;
    b <= 2'b10;
    $display("a: %b, b: %b, g: %b, e: %b, l: %b", a, b, g, e, l);
    $finish;
    
  end
  
endmodule
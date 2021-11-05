`timescale 1ns / 100ps

module multiplier_tb;
  reg [0:1]a = 2'b00;
  reg [0:1]b = 2'b00;
  wire [0:3]m;
  
  multiplier dut(
    .a(a),
    .b(b),
    .m(m)
  );
  
  initial begin
    $dumpfile("dump.vcd");
    $dumpvars;
    #10;
    a <= 2'b01;
    b <= 2'b11;
    #1;
    $display("a: %b, b: %b, m: %b", a, b, m);
    #10;
    a <= 2'b11;
    b <= 2'b10;
    $display("a: %b, b: %b, m: %b", a, b, m);
    #10;
    a <= 2'b10;
    b <= 2'b10;
    $display("a: %b, b: %b, m: %b", a, b, m);
    #10;
    a <= 2'b11;
    b <= 2'b11;
    $display("a: %b, b: %b, m: %b", a, b, m);
    #10;
    $finish;
    
  end
  
endmodule
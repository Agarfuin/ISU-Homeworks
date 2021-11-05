`timescale 1ns / 100ps

module half_adder_tb;
  reg a;
  reg b;
  wire s;
  wire cout;
  
  half_adder dut(
    .a(a),
    .b(b),
    .s(s),
    .cout(cout)
  );
  
  initial begin
    $dumpfile("dump.vcd");
    $dumpvars;
    #1;
    a = 0;
    b = 0;
    #1;
    a = 1;
    b = 0;
    #1;
    a = 0;
    b = 1;
    #1;
    a = 1;
    b = 1;
    #5;
    $finish;
    
  end
  
endmodule
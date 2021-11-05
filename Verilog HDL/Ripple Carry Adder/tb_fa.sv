`timescale 1ns / 100ps

module full_adder_tb;
  
  reg a;
  reg b;
  reg cin;
  wire s;
  wire cout;
  
  full_adder full_adder_dut(
    .a(a),
    .b(b),
    .cin(cin),
    .s(s),
    .cout(cout)
  );
  
  initial begin
    $dumpfile("dump.vcd");
    $dumpvars(1);
    #1;
    a = 0;
    b = 0;
    cin = 0;
    #1;
    cin = 1;
    #1;
    b = 1;
    cin = 0;
    #1;
    cin = 1;
    #1;
    a = 1;
    b = 0;
    cin = 0;
    #1;
    cin = 1;
    #1;
    b = 1;
    cin = 0;
    #1;
    cin = 1;
    #5;
    $finish;
    
  end
  
endmodule
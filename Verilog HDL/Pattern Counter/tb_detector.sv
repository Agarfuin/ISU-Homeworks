`timescale 1ns / 100ps

module detector_tb;
  reg clk;
  reg rst;
  reg cin;
  wire cout;
  
  detector dut(
    .cin(cin),
    .clk(clk),
    .rst(rst),
    .cout(cout)
  );
  
  initial begin
    $dumpfile("dump.vcd");
    $dumpvars;
    clk = 0;
    rst = 1;
    #5 rst = 0;
    cin = 1;
    #10 cin = 1;
    #10 cin = 0;
    #10 cin = 1;
    #10 cin = 0;
    #10 cin = 1;
    #10 cin = 0;
    #10 cin = 0;
    #10 cin = 1;
    #10 cin = 0;
    #10 cin = 1;
    #10 cin = 0;
    #50;
    $finish;
  end
  
  always begin
    #5;
    clk = ~clk;
  end

endmodule

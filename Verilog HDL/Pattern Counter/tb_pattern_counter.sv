`timescale 1ns / 100ps

module detector_tb;
  reg clk;
  reg rst;
  reg data_in;
  wire detect;
  wire [7:0] count;
  
  detector dut(
    .data_in(data_in),
    .clk(clk),
    .rst(rst),
    .detect(detect),
    .count(count)
  );
  
  initial begin
    $dumpfile("dump.vcd");
    $dumpvars;
    clk = 0;
    rst = 1;
    #5 rst = 0;
    data_in = 1;
    repeat(1000) @ (posedge clk) begin
      #10;
      data_in <= $random %2;
    end
    #50;
    $finish;
  end
  
  always begin
    #5;
    clk = ~clk;
  end

endmodule

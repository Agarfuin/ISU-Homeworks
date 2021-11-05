`timescale 1ns/100ps

module adder_subtractor_tb;
  reg [3:0] a;
  reg [3:0] b;
  reg cin;
  wire [3:0] s;
  wire cout;
  wire ovf;
  integer i;
  integer j;
  
  adder_subtractor adder_subtractor_dut(
    .a(a),
    .b(b),
    .cin(cin),
    .cout(cout),
    .s(s),
    .ovf(ovf)
    );
  
  initial begin 
    $dumpfile("dump.vcd"); 
    $dumpvars(1);
    #1;
    cin = 0;
    for(i=0;i<16;i=i+1)
      begin
        a = i;
        for(j=0;j<16;j=j+1)
          begin
            b = j;
            #1;
          end
      end
    #10;
    cin = 1;
    for(i=0;i<16;i=i+1)
      begin
        a = i;
        for(j=0;j<16;j=j+1)
          begin
            b = j;
            #1;
          end
      end
    #5;
    $finish;
  end
endmodule
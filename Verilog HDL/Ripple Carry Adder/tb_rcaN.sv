`timescale 1ns/100ps

module ripple_carry_adder_tb;
  reg [3:0] a;
  reg [3:0] b;
  reg cin;
  wire [3:0] s;
  wire cout;
  integer i;
  integer j;
  
  ripple_carry_adder ripple_carry_adder_dut(
    .a(a),
    .b(b),
    .cin(cin),
    .cout(cout),
    .s(s)
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
    #5;
    $finish;
  end
endmodule
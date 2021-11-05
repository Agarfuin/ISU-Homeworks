`timescale 1ns / 100ps

module detector(
  input cin,
  input clk,
  input rst,
  output reg cout
);
  
  reg [2:0] ps;
  reg [2:0] ns;
  
  parameter s0 = 3'b000, s1 = 3'b001, s2 = 3'b010, s3 = 3'b011, s4 = 3'b100;

  always @ (posedge clk) begin
    if (rst)
      ps<= s0;
    else
      ps <= ns;
  end
  
  always @ (ps or cin) begin
    case (ps)
        
      s0: begin
        cout = 0;
        if (cin)
          ns = s1;
        else
          ns = s0;
      end
        
      s1:  begin
        cout = 0;
        if (cin)
          ns = s1;
        else
          ns = s2;
      end
        
      s2:  begin
        cout = 0;
        if (cin)
          ns = s3;
        else
          ns = s0;
      end
        
      s3:  begin
        cout = 0;
        if (cin)
          ns = s1;
        else
          ns = s4;
      end
        
      s4: begin
        cout = 1;
        if (cin)
          ns = s3;
        else
          ns = s0;
      end
        
      default: begin
        cout = 0;
        ns = s0;
      end
        
    endcase
      
  end
endmodule
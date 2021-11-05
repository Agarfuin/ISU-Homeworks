`timescale 1ns / 100ps

module detector(
  input data_in,
  input clk,
  input rst,
  output reg [7:0] count,
  output reg detect
);
  
  reg [2:0] ps;
  reg [2:0] ns;
  reg [7:0] counter;
  
  parameter s0 = 3'b000, s1 = 3'b001, s2 = 3'b010, s3 = 3'b011, s4 = 3'b100;
  
  initial begin
    counter = 0;
  end

  always @ (posedge clk) begin
    if (rst)
      ps<= s0;
    else
      ps <= ns;
  end
  
  always @ (posedge detect) begin
    counter = counter + 1;
    count <= counter;
  end
  
  always @ (ps or data_in) begin
    case (ps)
      s0: begin
        detect = 0;
        if (data_in)
          ns = s1;
        else
          ns = s0;
      end

      s1:  begin
        detect = 0;
        if (data_in)
          ns = s1;
        else
          ns = s2;
      end
      
      s2:  begin  
        detect = 0;
        if (data_in)
          ns = s3;
        else
          ns = s0;
      end
      
      s3:  begin
        detect = 0;
        if (data_in)
          ns = s1;
        else
          ns = s4;
      end
      
      s4: begin
        detect = 1;
        if (data_in)
          ns = s3;
        else
          ns = s0;
      end
        
      default: begin
        detect = 0;
        ns = s0;
      end
        
    endcase
  end
  
endmodule
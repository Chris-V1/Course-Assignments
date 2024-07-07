// Cristian Molano - cmola002
// January 27, 2021
// Section 23

module edgedetector_bh( 
input wire clk,
input wire signal,
output reg outedge );
  
wire slow_clk ;
  
reg [1:0] c_state ; 
reg [1:0] r_state ;
  
// Define your FSM states
localparam ZERO = 'd0; 
localparam CHANGE = 'd1; 
localparam ONE = 'd2;
  
 //same project with the given code.
  
clkdiv c1(clk, slow_clk );
  
// Comb. logic.
  
always @(*) begin

  	case (r_state)

      ZERO : begin
		c_state = signal ? CHANGE :ZERO ;
		outedge = 'd0 ; 
      end
      
      CHANGE : begin
      	c_state = signal ? CHANGE :ZERO ;
		outedge = 'd1 ; 
      end
      
      ONE : begin
      	c_state = signal ? CHANGE :ZERO ;
		outedge = 'd2 ; 
      end
      
    default : begin 
      c_state = ZERO ; 
      outedge = 'd0 ;
    end 
    
 endcase
  
end
// Seq. logic
always @( posedge slow_clk ) begin
	r_state <= c_state ; 
end
  
endmodule




module clkdiv(clk,clk_out); 
  
 input clk;
 output clk_out;
 reg [15:0] COUNT;
 assign clk_out=COUNT[15];
  
 always @(posedge clk) 
 begin
 	COUNT = COUNT + 1; 
 end
  
endmodule

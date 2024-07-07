// Cristian Molano - cmola002
// January 27, 2021
// Section 23

`timescale 1ns / 1ps
module fasystem_bh( 
input wire clk, // clock
input wire call_button , 
input wire cancel_button , 
output reg light_state
//output wire light_state
);
  
// Internal wire
reg c_state ;
  
// Combinatorial block 
  
always @(*) begin
  
		case ({call_button,cancel_button})
		2'b00: c_state = light_state ? 'd1 : 'd0 ; 			
        2'b01: c_state = 'd0 ;
		2'b10: c_state = 'd1 ;
		2'b11: c_state = 'd1;
          
		default : c_state = 'd0 ;
		endcase 
end
  
  
// Sequential block
  
always @( posedge clk ) begin
  
  light_state <= c_state ; 

end
 
endmodule


`timescale 1ns / 1ps
module clkdiv(clk,reset,clk_out);

	input clk;
	input reset;
	output clk_out;

  	reg [15:0] COUNT;

  assign clk_out=COUNT[15];

	always @(posedge clk)
	begin
		if (reset == 1'b1)
			COUNT <= 0;
		else
			COUNT <= COUNT + 1'b1;
	end
  
endmodule

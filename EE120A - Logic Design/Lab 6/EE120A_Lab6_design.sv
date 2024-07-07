// Cristian Molano - cmola002
// February 14, 2021
// Section 23

`timescale 1ns / 1ps
///////////////////////////////////////////////////////////////////////////
///////
///////////////////////////////////////////////////////////////////////////
///////
module laser_surgery_sys #(
 parameter NBITS = 32
)
(
input wire b ,
input wire clk ,
output reg light
);
reg reset;
wire timer;
reg [1:0] current_state ;
reg [1:0] next_state ; 
  

  
  
  
wire [NBITS-1:0] cnt_ini ;
wire [NBITS-1:0] cnt_rst ;
// --------------------------------------
// Sequential logic
// --------------------------------------
always @(posedge clk) begin
current_state = next_state ;
end
// --------------------------------------
// Comb. Logic
// --------------------------------------
assign cnt_ini = 32'h0000 ;
assign cnt_rst = 25'h0000; // 10 secs ( 25 MHZ internal clock )
// --------------------------------------
// Comb. Logic - FSM
// --------------------------------------
localparam OFF = 2'b00 ;
localparam START = 2'b01 ;
localparam ON = 2'b10 ;
always @( current_state ) begin
case (current_state)
 OFF : begin
 // your code for state transition       ???????????????????
 end

 START : begin
 // your code for state transition	     ???????????????????
end
 ON: begin
 // your code for state transition		 ???????????????????
 end 
  
default: begin
light = 1'b0 ;
reset = 1'b0 ;
next_state = OFF ;
 end
endcase
end
// --------------------------------------
// Timer instantiation
// --------------------------------------
timer_st #( .NBITS(NBITS) ) timerst (
.timer(timer),
.clk(clk),
.reset(reset) ,
.cnt_ini(cnt_ini) ,
.cnt_rst(cnt_rst)
);
endmodule 






module flopr #( parameter NBITS = 16 )(
 input clk,
    input reset,
    input [NBITS-1:0] cnt_ini,
    input [NBITS-1:0] nextq,
    output[NBITS-1:0] q
);
reg [NBITS-1:0] iq ;
  
always @(posedge clk) begin 
  
  
if (reset) begin
	iq <= cnt_ini ;
 end
 else begin
		iq <= nextq;
 end
end
  
assign q = iq ;
endmodule






module comparatorgen_st #( parameter NBITS = 16 )(
output wire r ,
input wire[NBITS-1:0] a ,
input wire[NBITS-1:0] b );
wire [NBITS-1:0] iresult ;
genvar k ;
generate
for (k=0; k < NBITS; k = k+1)
begin : blk
 xor c1 (iresult[k], a[k], b[k] ) ;
end
endgenerate
// Reduction plus negation
assign r = ~(|iresult);
endmodule






module fulladder_st(
output wire r,
output wire cout,
input wire a,
input wire b,
input wire cin
) ;
assign r = (a ^ b) ^ (cin) ;
assign cout = (a & b) | ( a & cin ) | ( b & cin ) ;
endmodule






module addergen_st #( parameter NBITS = 16 )(
output wire[NBITS-1:0] r ,
output wire cout ,
input wire[NBITS-1:0] a ,
input wire[NBITS-1:0] b ,
input wire cin ) ;
wire [NBITS:0] carry;
assign carry[0]= cin ;
genvar k ;
generate
for (k=0; k < NBITS; k = k+1)
begin : blk
 fulladder_st FA (
   .r(r[k]),
   .cout(carry[k+1]),
   .a(a[k]),
   .b(b[k]),
   .cin(carry[k]) ) ;
end
  
endgenerate
assign cout = carry[NBITS] ;
endmodule






module adder #( parameter NBITS = 16 )(
input [NBITS-1:0] q ,
input [NBITS-1:0] cnt_ini ,
input [NBITS-1:0] cnt_rst ,
output[NBITS-1:0] nextq,
output tick
);
wire same ;
wire[NBITS-1:0] inextq; 
  
// ------------------------------------------------
// inextq = q + 1 ;
// ------------------------------------------------
addergen_st #(.NBITS(NBITS))
nextval ( .r(inextq), // Next value
 .cout(), // Carry out - Don't use
 .a(q), // Current value
 .b(16'b0000_0001), // Plus One
 .cin(16'b0000_0000) ) ; // No carry in
// ------------------------------------------------
// Are inextq and cnt_rst equal ?
// ------------------------------------------------
comparatorgen_st #(.NBITS(NBITS))
comparator (
.r(same) ,
.a(inextq),
.b(cnt_rst) );
// -----------------------------------------------------------------
// If they are the same produce a tick and set the value for nextq
// -----------------------------------------------------------------
assign tick = (same) ? 'd1 : 'd0 ;
assign nextq = (same) ? cnt_ini : inextq ;
endmodule








module timer_st #(
 parameter NBITS = 32
)
(
 output wire timer ,
 input wire clk ,
 input wire reset,
 input [NBITS-1:0] cnt_ini ,
 input [NBITS-1:0] cnt_rst
);
  
wire [NBITS-1:0] q ;
wire [NBITS-1:0] qnext ;
  
// Compute the next value
  
adder #( .NBITS(NBITS ) )
 c1 (.q(q),
.cnt_ini(cnt_ini),
.cnt_rst(cnt_rst),
.nextq(qnext),
.tick(timer) );
// Save the next state
flopr #( .NBITS(NBITS ) )
 c2 (.clk(clk),
.reset(reset),
.cnt_ini(cnt_ini),
.nextq(qnext),
.q(q) );
endmodule


  
  
  
  
  
  

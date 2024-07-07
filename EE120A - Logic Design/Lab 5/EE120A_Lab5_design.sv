// Cristian Molano - cmola002
// February 4, 2021
// Section 23


`timescale 1ns / 1ps
module falogic(
output r, // We label our output as r instead of z
input x,
input y,
input cin
 );
  
  
wire t1;
xor cx1 ( t1, x,y );
xor cx2 ( r, t1, cin );
  
endmodule

`timescale 1ns / 1ps
module register_logic(
 input clk,
 input enable ,
 input [4:0] Data ,
 output reg [4:0] Q ) ;
  
// on real FPGA board which has clk signal, we use the following always statement:
// always @(posedge clk )
// begin
// if ( enable) begin
// Q = Data;
// end
// end
// endmodule
  
// for simulation, we force the statement to execute without clk signal:
always @(*) begin
 if ( enable) begin
 	Q = Data;
   
    end
end
endmodule








`timescale 1ns / 1ps
module carrylogic(
output [3:0] cout ,
input cin,
input [3:0] x,
input [3:0] y
 );
  
// Computing all gx
  
wire g0, g1, g2, g3 ;
  
assign g0 = x[0] & y[0];
assign g1 = x[1] & y[1];
assign g2 = x[2] & y[2];  ///////////// Implementation Code
assign g3 = x[3] & y[3];  ///////////// Implementation Code
  
  
// Computing all px
wire p0, p1, p2, p3 ;
  
  
assign p0 = x[0] + y[0] ;
assign p1 = x[1] + y[1] ;
assign p2 = x[2] + y[2] ; ///////////// Implementation Code
assign p3 = x[3] + y[3] ; ///////////// Implementation Code
  
  
// Computing all carries
  
// ?????????????????????????
assign cout[0] = g0 | ( p0 & cin);
assign cout[1] = g1 | ( p1 & ( g0 | (p0 & cin) ) );
  assign cout[2] = g2 | (p2 & g1) | (p2 & p1 & g0) | (p2 & p1 & p0 & cin);
assign cout[3] = g3 | (p3 & g2) | (p3 & p2 & g1) | (p3 & p2 & p1 & g0) | (p3 & p2 & p1 & p0 & cin);
  
//assign cout[2] = g2 | (p2 & (p1 | (p1 & (g0 | (p0 & cin) )))); ///////////// Implementation Code
//assign cout[3] = g3 | (p3 & (p2|  (p2 & (g2 | ( p2 & (g1 | ( p1 & ( g0 | (p0 & cin) ))))))) ); ///////////// Implementation Code
                       
endmodule
// ?????????????????????????
  
`timescale 1ns / 1ps 
module carrylookahead_st(
 input clk ,
 input cin,
 input [3:0] x,
 input [3:0] y,
 output cout,
 output [3:0] r
 ); 
  
  
wire [3:0] c;
wire [3:0] ir1 ;
wire [4:0] ir2 ;

// Compute Carries
carrylogic cx1 ( c, cin, x, y ) ;
  
// Compute R
falogic cx6 ( ir1[0], x[0], y[0], cin ) ;
// Your code (3 more full adders)
falogic cx7 ( ir1[1], x[1], y[1], c[0] ) ; ///////////// Implementation Code
falogic cx8 ( ir1[2], x[2], y[2], c[1] ) ; ///////////// Implementation Code
falogic cx9 ( ir1[3], x[3], y[3], c[2] ) ; ///////////// Implementation Code
  
  
  
// Register
register_logic cx10(clk, 1'b1,{c[3],ir1},ir2);
  
// Results
assign r = ir2[3:0] ;
assign cout = ir2[4] ;
  
endmodule
  
  
  
  
  

  
  
  









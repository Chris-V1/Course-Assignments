// Cristian Molano - cmola002
// January 12, 2021
// Section 23


`timescale 1ns / 1ps
module lab1_structural_tb();
// Inputs
reg bot_reg = 1'b0; reg top_reg = 1'b0; // Outputs
wire a;
wire b; wire c; wire d;
// Instantiate your circuit (lab1_structural)
lab1_structural UUT (
// Connect your testbench to your circuit
.A(a),
.B(b),
.C(c),
.D(d), .Bot(bot_reg), .Top(top_reg)
);
  
// Assign inputs to your circuit 
// Test for expected output 
initial begin
// The following line is EDA Playground specific.
// Make sure to add it to all your future testbenches 
$dumpfile("dump.vcd"); $dumpvars;
  
  
  
// Testcase #1
  
$display("Testcase #1");
// Assign inputs
bot_reg = 1'b1;
top_reg = 1'b1;
#40; // Wait 40 ns
// Check for expected output 
if ( {a,b,c,d} != 4'b1010 )
	$display ("\t Result is wrong %b ", {a,b,c,d}); 
else
	$display ("\t Testcase #1 successful");
  
  
// Testcase #2
  
$display("Testcase #2");
// Assign inputs
bot_reg = 1'b0;
top_reg = 1'b0;
#40;
// Check for expected output 
if ( {a,b,c,d} != 4'b0101 )
	$display ("\t Result is wrong %b ", {a,b,c,d}); 
else
	$display ("\t Testcase #2 successful");
  
  
// Add testcase #3 and #4 below
  
  
// Testcase #3
$display("Testcase #3");
// Assign inputs
bot_reg = 1'b1;
top_reg = 1'b0;
#40; // Wait 40 ns
// Check for expected output 
  if ( {a,b,c,d} != 4'b0110 )
	$display ("\t Result is wrong %b ", {a,b,c,d}); 
else
  $display ("\t Testcase #3 successful");
  
  
// Testcase #4
$display("Testcase #4");
// Assign inputs
bot_reg = 1'b0;
top_reg = 1'b1;
#40; // Wait 40 ns
// Check for expected output 
  if ( {a,b,c,d} != 4'b0110 )
	$display ("\t Result is wrong %b ", {a,b,c,d}); 
else
  $display ("\t Testcase #4 successful");


  
  
end
  
endmodule

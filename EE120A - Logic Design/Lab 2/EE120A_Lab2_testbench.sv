// Cristian Molano - cmola002
// January 16, 2021
// Section 23


// `timescale 2ns / 1ps
`timescale 1ns / 1ps 
  
//module mux_tb;
//		// Inputs 
//  		reg s1; 
//  		reg s0; 
//  		reg i0; 
//  		reg i1; 
//  		reg i2;
//  		reg i3;
//  
//  		// Outputs 
//  		wire d;
 
  
  	
  
  
//  		.s1(s1), 
//  		.s0(s0), 
//  		.i0(i0), 
//  		.i1(i1), 
//  		.i2(i2), 
//  		.i3(i3), 
//  		.d(d)
  
//  };
  
  
  initial begin
    
  $dumpfile("dump.vcd"); $dumpvars;
    
  i0 = 1; 
  i1 = 0; 
  i2 = 1; 
  i3 = 0;
    
  s1 = 0;
  s0 = 0;
  #100;
  $display("TC11 ");
  if ( d != i0 ) $display ("Result is wrong");
    
    
  s1 = 0;
  s0 = 1;
  #100;
  $display("TC12 ");
  if ( d != i1 ) $display ("Result is wrong");
    
  s1 = 1;
  s0 = 0;
  #100;
  $display("TC13 ");
  if ( d != i2 ) $display ("Result is wrong");
    
  s1 = 1;
  s0 = 1;
  #100;
  $display("TC14 ");
  if ( d != i3 ) $display ("Result is wrong");
    
  // Your test cases
    
 end
  
  
endmodule

  

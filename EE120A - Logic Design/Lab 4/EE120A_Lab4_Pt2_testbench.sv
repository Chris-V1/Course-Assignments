// Cristian Molano - cmola002
// January 27, 2021
// Section 23

`timescale 1ns / 1ps

module edgedetector_tb;
  //inputs
  wire clk;
  wire signal;
  
  //outputs
  reg outedge;
  
  edgedetector_bh uut(
    .clk(clk),
    .signal(signal)
    
  );
  
  initial begin
    
    $dumpfile("dump.vcd"); $dumpvars;
    
    //Test Case 1
    clk = 0; signal = 0;
    #100 // Wait 100ns
    $display("Testcase #1");
    if (outedge != 0) $display ("Result is wrong %b", outedge);

    
    //Test Case 2
    clk = 1; signal = 0;
    #100 // Wait 100ns
    $display("Testcase #2");
    if (outedge != 1) $display ("Result is wrong %b", outedge);
    
    
     //Test Case 3
    clk = 0; signal = 1;
    #100 // Wait 100ns
    $display("Testcase #2");
    if (outedge != 0) $display ("Result is wrong %b", outedge);
    
    
    //Test Case 4
    clk = 1; signal = 1;
    #100 // Wait 100ns
    $display("Testcase #2");
    if (outedge != 0) $display ("Result is wrong %b", outedge);

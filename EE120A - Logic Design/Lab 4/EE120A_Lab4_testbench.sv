// Cristian Molano - cmola002
// January 27, 2021
// Section 23


`timescale 1ns / 1ps

module fasystem_tb;
  //inputs
  reg clk; // clock
  reg call_button;
  reg cancel_button;
  reg c_state;

  //outputs
  wire light_state; // changed to wire instead of reg

  fasystem_bh uut(
    .clk(clk),
    .call_button(call_button),
    .cancel_button(cancel_button)

  );

  initial begin

    $dumpfile("dump.vcd"); $dumpvars;

    // Test Case 1
    call_button = 0;  cancel_button = 0; c_state = 0; 
    #100 // Wait 100 ns
    $display("Testcase #1");
    if(light_state != 0) $display ("Result is wrong %b", light_state);

    // Test Case 2
    call_button = 0;  cancel_button = 0; c_state = 1; 
    #100 // Wait 100 ns
    $display("Testcase #2");
    if(light_state != 1) $display ("Result is wrong %b", light_state);

    // Test Case 3
    call_button = 0;  cancel_button = 1; c_state = 0; 
    #100 // Wait 100 ns
    $display("Testcase #3");
    if(light_state != 0) $display ("Result is wrong %b", light_state);

    // Test Case 4
    call_button = 0;  cancel_button = 1; c_state = 1;
    #100 // Wait 100 ns
    $display("Testcase #4");
    if(light_state != 0) $display ("Result is wrong %b", light_state);

    // Test Case 5
    call_button = 1;  cancel_button = 0; c_state = 0;
    #100 // Wait 100 ns
    $display("Testcase #5");
    if(light_state != 1) $display ("Result is wrong %b", light_state);

    // Test Case 6
    call_button = 1;  cancel_button = 0; c_state = 1;
    #100 // Wait 100 ns
    $display("Testcase #6");
    if(light_state != 1) $display ("Result is wrong %b", light_state);

    // Test Case 7
    call_button = 1;  cancel_button = 1; c_state = 0;
    #100 // Wait 100 ns
    $display("Testcase #7");
    if(light_state != 1) $display ("Result is wrong %b", light_state);

    // Test Case 8
    call_button = 1;  cancel_button = 1; c_state = 1;
    #100 // Wait 100 ns
    $display("Testcase #8");
    if(light_state != 1) $display ("Result is wrong %b", light_state);

  end
endmodule

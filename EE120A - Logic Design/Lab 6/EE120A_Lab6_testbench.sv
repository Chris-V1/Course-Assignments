// Cristian Molano - cmola002
// February 14, 2021
// Section 23

`timescale 1ns / 1ps

module laser_surgery_sys #;
  //inputs
  wire b;
  wire clk;
  
  //output
  reg light;
  
  laser_surgery_sys # uut(
    .b(b),
    .clk(clk)
    
  );
    
  
  initial begin
    
    $dumpfile("dumo.vcd"); $dumpvars;
    
    // Test Case 1
    b = 0; clk = 0;
    #100
    $display("Testcase #1");
    if(light != 0) $display("Wrong Output", light);
    
    // Test Case 2
    b = 0; clk = 1;
    #100
    $display("Testcase #2");
    if(light != 1) $display("Wrong Output", light);
    
    // Test Case 3
    b = 1; clk = 0;
    #100
    $display("Testcase #3");
    if(light != 0) $display("Wrong Output", light);
    
    // Test Case 4
    b = 1; clk = 1;
    #100
    $display("Testcase #4");
    if(light != 1) $display("Wrong Output", light);
    
  end
  
endmodule
  
  
  
  // First Test Bench ^
  
  
`timescale 1ns / 1ps

module flopr #( parameter NBITS = 16 );
  //inputs
  reg clk;
  reg reset;
  reg cnt_ini;
  reg nextq;
  
  
  //output
  reg q;
  
  flopr #( parameter NBITS = 16 ) uut(
    .clk(clk),
    .reset(reset),
    .cnt_ini(cnt_ini),
    .nextq(nextq)
    
  );
  
  
  initial begin
    
    $dumpfile("dumo.vcd"); $dumpvars;
    
    clk = 0; reset 0; cnt_ini = 0; nextq 0;
    #100
    $display("Testcase #1");
    if(q != 0) $display("Wrong Output", q);
    
    clk = 0; reset 0; cnt_ini = 0; nextq 1;
    #100
    $display("Testcase #2");
    if(q !=1) $display("Wrong Output", q);
    
    clk = 0; reset 0; cnt_ini = 1; nextq 0;
    #100
    $display("Testcase #3");
    if(q != 1) $display("Wrong Output", q);
    
    clk = 0; reset 1; cnt_ini = 0; nextq 0;
    #100
    $display("Testcase #4");
    if(q != 0) $display("Wrong Output", q);
    
    clk = 1; reset 0; cnt_ini = 0; nextq 0;
    #100
    $display("Testcase #5");
    if(q != 0) $display("Wrong Output", q);
    
    clk = 1; reset 1; cnt_ini = 1; nextq 1;
    #100
    $display("Testcase #6");
    if(q != 0) $display("Wrong Output", q);
    
    clk = 0; reset 0; cnt_ini = 1; nextq 1;
    #100
    $display("Testcase #7");
    if(q != 1) $display("Wrong Output", q);
    
    clk = 1; reset 1; cnt_ini = 0; nextq 0;
    #100
    $display("Testcase #8");
    if(q != 0) $display("Wrong Output", q);
    
    
      end
  
endmodule
  
  
  
  // Second Test Bench ^
  
    
`timescale 1ns / 1ps

module comparatorgen_st #( parameter NBITS = 16 );
  //inputs
  wire a;
  wire b;
  
  
  //output
  wire r;
  
  comparatorgen_st #( parameter NBITS = 16 ) uut(
    .a(a),
    .b(b)
    
  );
  
  
  initial begin
    
    $dumpfile("dumo.vcd"); $dumpvars;
    a = 0; b = 0;
    #100
    $display("Testcase #1");
    if(r != 0) $display("Wrong Output", r);
    
    $dumpfile("dumo.vcd"); $dumpvars;
    a = 0; b = 1;
    #100
    $display("Testcase #2");
    if(r != 0) $display("Wrong Output", r);
    
    $dumpfile("dumo.vcd"); $dumpvars;
    a = 1; b = 0;
    #100
    $display("Testcase #3");
    if(r != 1) $display("Wrong Output", r);
    
    $dumpfile("dumo.vcd"); $dumpvars;
    a = 1; b = 1;
    #100
    $display("Testcase #4");
    if(r != 1) $display("Wrong Output", r);
    
  
  
    end
  
endmodule
  
  
  
  // Third Test Bench ^ 
  
  
  
  
  
  
`timescale 1ns / 1ps

module fulladder_st;
  //inputs
  wire a;
  wire b;
  wire cin;
  
  
  //output
  wire r;
  wire cout;
  
  module fulladder_st uut(
    .a(a).
    .b(b).
    .cin(cin)
    
  );
  
  
  initial begin
    
    $dumpfile("dumo.vcd"); $dumpvars;
    
    a = 0; b = 0; cin = 0;
    #100
    $display("Testcase #1");
    if(r != 0) $display("Wrong Output", cout);
    
    a = 0; b = 0; cin = 1;
    #100
    $display("Testcase #2");
    if(r != 1) $display("Wrong Output", cout);
    
    a = 0; b = 1; cin = 1;
    #100
    $display("Testcase #3");
    if(r != 1) $display("Wrong Output", cout);
    
    a = 1; b = 1; cin = 0;
    #100
    $display("Testcase #4");
    if(r != 0) $display("Wrong Output", cout);
    
    a = 1; b = 1; cin = 1;
    #100
    $display("Testcase #5");
    if(r != 1) $display("Wrong Output", cout);
    
    
     end
  
endmodule
  
  
  
  // Forth Test Bench ^ 
    
     
`timescale 1ns / 1ps

  module addergen_st #( parameter NBITS = 16 );
  //inputs
  wire a;
  wire b;
  wire cin;
  
  
  //output
  wire r;
  wire cout;
  wire carry; // Just assumed it would be an output since it 					 didn't specify 
  
  module fulladder_st uut(
    .a(a).
    .b(b).
    .cin(cin)
    
  );
  
  
  initial begin
    
    $dumpfile("dumo.vcd"); $dumpvars;
    
    a = 0; b = 0; cin = 0;
    #100
    $display("Testcase #1");
    if(carry != 0) $display("Wrong Output", cout);
   
    a = 0; b = 0; cin = 1;
    #100
    $display("Testcase #2");
    if(carry != 1) $display("Wrong Output", cout);
    
    a = 0; b = 1; cin = 1;
    #100
    $display("Testcase #3");
    if(carry != 1) $display("Wrong Output", cout);
    
    a = 1; b = 1; cin = 0;
    #100
    $display("Testcase #4");
    if(carry != 0) $display("Wrong Output", cout);
    
    a = 1; b = 1; cin = 1;
    #100
    $display("Testcase #5");
    if(carry != 1) $display("Wrong Output", cout);
    
    
      end
  
endmodule
  
  
  
  // Fifth Test Bench ^ 
    
    
`timescale 1ns / 1ps

  module adder #( parameter NBITS = 16 );
  //inputs
  reg q;
  reg cnt_ini;
  reg cnt_rst;
  
  
  //output
  wire nextq;
  wire tick;
  
  
  module adder uut(
    .q(q),
    .cnt_ini(cnt_ini),
    .cnt_rst(cnt_rst)
    
  );
  
  
  initial begin
    
    $dumpfile("dumo.vcd"); $dumpvars;
    
    q = 0; cnt_ini = 0; cnt_rst = 0;
    #100
    $display("Testcase #1");
    if(tick != 0) $display("Wrong Output", nextq);
    
    
    q = 0; cnt_ini = 1; cnt_rst = 1;
    #100
    $display("Testcase #2");
    if(tick != 1) $display("Wrong Output", nextq);
    
    
    q = 1; cnt_ini = 1; cnt_rst = 0;
    #100
    $display("Testcase #3");
    if(tick != 1) $display("Wrong Output", nextq);
    
    q = 0; cnt_ini = 0; cnt_rst = 1;
    #100
    $display("Testcase #4");
    if(tick != 0) $display("Wrong Output", nextq);
    
    q = 0; cnt_ini = 1; cnt_rst = 0;
    #100
    $display("Testcase #5");
    if(tick != 0) $display("Wrong Output", nextq);
    
    q = 1; cnt_ini = 1; cnt_rst = 1;
    #100
    $display("Testcase #5");
    if(tick != 1) $display("Wrong Output", nextq);
    
    
     end
  
endmodule
  
  
  
  // Sixth Test Bench ^ 
    
    
    
`timescale 1ns / 1ps

  module timer_st #(parameter NBITS = 32);
  //inputs
  wire clk;
  wire reset;
  wire cnt_ini;
  wire cnt_rst;
  
  
  //output
  wire q;
  wire qnext;
  
  
    module timer_st #(parameter NBITS = 32)  uut(
      .cllk(clk),
      .reset(reset),
      .cnt_ini(cnt_ini),
      .cnt_rst(cnt_rst)
    
  );
  
  
  initial begin
    
    $dumpfile("dumo.vcd"); $dumpvars;
    
    clk = 0; reset = 0; cnt_ini = 0; cnt_rst = 0;
    #100
    $display("Testcase #1");
    if(tick != 0) $display("Wrong Output", nextq);
    
                            
    clk = 0; reset = 1; cnt_ini = 1; cnt_rst = 0;
    #100
    $display("Testcase #2");
    if(tick != 1) $display("Wrong Output", nextq);
       
                            
    clk = 1; reset = 1; cnt_ini = 0; cnt_rst = 1;
    #100
    $display("Testcase #3");
    if(tick != 1) $display("Wrong Output", nextq);
             
                            
    clk = 0; reset = 0; cnt_ini = 1; cnt_rst = 1;
    #100
    $display("Testcase #4");
    if(tick != 0) $display("Wrong Output", nextq);
                            
                            
    clk = 0; reset = 0; cnt_ini = 1; cnt_rst = 0;
    #100
    $display("Testcase #5");
    if(tick != 0) $display("Wrong Output", nextq);
    
    clk = 1; reset = 0; cnt_ini = 1; cnt_rst = 0;
    #100
    $display("Testcase #6");
    if(tick != 0) $display("Wrong Output", nextq);
                            
    
    end
  
endmodule
  
  
  
  // Seventh Test Bench ^ 
    
    
    
    
    
    
    

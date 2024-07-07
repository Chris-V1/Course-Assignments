// Cristian Molano - cmola002
// February 5, 2021
// Section 23


`timescale 1ns / 1ps
///////////////////////////////////////////////////////////////////////////
/////
///////////////////////////////////////////////////////////////////////////
/////
module carrylookahead_tb;
  
  
  // Inputs
  reg cin;
  reg [3:0] x;
  reg [3:0] y;
  reg clk;
  // Outputs
  wire cout;
  wire [3:0] r;
  
  reg [3:0] rx;
  integer index ;
   //always @(*) // no sensitivity list, so it always executes
  // begin
  // clk = 1; #100; clk = 0; #100; // 10ns period
  // end
  // Instantiate the Unit Under Test (UUT)
  carrylookahead_st uut (
        .clk(clk),
        .cin(cin),
        .x(x),
        .y(y),
        .cout(cout),
        .r(r)
  );
  
  
  
  
  initial begin
 $dumpfile("dump.vcd"); $dumpvars;
  		// Initialize Inputs
        cin = 'd0;
        y = 'd0;
        // r = x + 0 ; cout = 0;
   $display("TC11 ");
   for (index=0; index < 15; index = index + 1) begin
  
                    x = index;
                    #100;
                    if ( r != x ) $display ("Result is wrong");
                    if ( cout != 1'b0 ) $display ("Result is wrong -Carryout ");
  			end
   // r = x + 1 ; 
                                                  
                                                  
     cin = 1'b1;
     y = 4'b0;
 $display("TC12 ");
                                                  
 		for (index=0; index < 15; index = index + 1) begin
                      x = index ;
                      #100
          			  if ( r != (x + 'd1) ) $display ("Result is wrong %b %b" , r, (x+1) );
                                                      
					  if ( cout != 1'b0 ) $display ("Result is wrong -Carryout ");
			end
			// r = x + y + 1 ;
 	cin = 1'b1;
 	$display("TC13 ");
 		for (index=0; index < 8; index = index + 1) begin
                      x = index ;
                      y = index ;
                      #100;
          if ( r != (x + y +1 ) ) $display ("Result is wrong %b %b" , r, (x+y) );
                                                        
					  if ( cout != 1'b0 ) $display ("Result is wrong -Carryout ");
				end
                                                    
				// r = x + y + 1 ;
				cin = 1'b1;
$display("TC14 ");
    for (index=8; index < 16; index = index + 1) begin
      
            x = index ;
            y = index ;
            rx = x + y + cin ;
            #100;
            if ( r != rx ) $display ("Result is wrong %b %b" , r,rx );
			if ( cout != 1'b1 ) $display ("Result is wrong -Carryout ");
			end 
   end
               
endmodule                                      
                                          

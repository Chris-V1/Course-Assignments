// Cristian Molano - cmola002
// January 16, 2021
// Section 23

// module and3( 
// input wire a, 
// input wire b, 
// input wire c, 
// output wire r
// );
  
// assign r = a & b & c ; 
  
// endmodule



// structural model 
// module mux_st(
// Ports I/O 
//  input wire s1, 
//  input wire s0, 
//  input wire i0, 
//  input wire i1, 
//  input wire i2, 
//  input wire i3, 
//  output wire d 
// );
  
// wire r1, r2, r3, r4 ;
// and3 c1 ( ~s1,~s0, i0, r1 ) ;
  
// Your code goes here (3 cases left) 
// assign d = r1 | r2 | r3 | r4 ; 
// endmodule



// behavioral model 

module mux_bh(
// Ports I/O
  
 input wire s1, 
 input wire s0, 
 input wire i0, 
 input wire i1, 
 input wire i2, 
 input wire i3, 
 output reg d 
);
  
always @(*) begin
  
  	d = 1'b0 ;
  
	case ( {s1,s0} )

  		2'b00 : d = i0 ;
		// your code goes here (3 cases left)
      
	endcase 

end
  
endmodule

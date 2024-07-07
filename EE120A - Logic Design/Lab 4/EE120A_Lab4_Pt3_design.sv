// Cristian Molano - cmola002
// January 28, 2021
// Section 23


module bcdto7led_bh( 
input wire sw0 ,
input wire sw1 ,
input wire sw2 ,
input wire sw3 ,
  
output reg a , 
output reg b , 
output reg c , 
output reg d , 
output reg e ,
  
  
output reg f ,
output reg g , 
output reg dp
  
	);
  
// Internal wire
wire [3:0] bundle ;
  
assign bundle = {sw3,sw2,sw1,sw0 } ; 
  
always @(*) begin
  
		a = 1'b1 ; 
  		b = 1'b1 ; 
  		c = 1'b1 ; 
  		d = 1'b1 ; 
  		e = 1'b1 ; 
  		f = 1'b1 ; 
  		g = 1'b1 ; 
  		dp = 1'b1;
  
  
case ( bundle )
  
		4'b0000 : begin // 0 a = 1'b0 ;
			b = 1'b0 ; 
            c = 1'b0 ; 
            d = 1'b0 ; 
            e = 1'b0 ; 
            f = 1'b0 ;
          
		end
  
		4'b0001 : begin // 1
        b = 1'b0 ;
        c = 1'b0 ;
          
        end
  
  		4'b0010 : begin // 2 
          	a = 1'b0 ;
          	b = 1'b0 ; 
          	d = 1'b0 ; 
         	e = 1'b0 ; 
          	g = 1'b0 ;
          
		end
  
  
		4'b0011 : begin // 3 
         	a = 1'b0 ;
          	b = 1'b0 ; 
          	c = 1'b0 ; 
          	d = 1'b0 ; 
          	g = 1'b0 ;
          
		end
  
		4'b0100 : begin // 4
          
			b = 1'b0 ; 
          	c = 1'b0 ; 
          	f = 1'b0 ; 
          	g = 1'b0 ;
          
		end
  
  
		4'b0101 : begin // 5 
          	a = 1'b0 ;
			c = 1'b0 ; 
          	d = 1'b0 ; 
          	f = 1'b0 ; 
          	g = 1'b0 ;
          
		end
  
  
  		4'b0101 : begin // 6
          	a = 1'b0 ;
			c = 1'b0 ; 
          	d = 1'b0 ; 
          	f = 1'b0 ; 
          	g = 1'b0 ;
          
		end
  
  
  		4'b0101 : begin // 7
          	a = 1'b0 ;
			c = 1'b0 ; 
          	d = 1'b0 ; 
          	f = 1'b0 ; 
          	g = 1'b0 ;
          
		end
  
  		4'b0101 : begin // 8
          	a = 1'b0 ;
			c = 1'b0 ; 
          	d = 1'b0 ; 
          	f = 1'b0 ; 
          	g = 1'b0 ;
          
		end
  
  		4'b0101 : begin // 9
          	a = 1'b0 ;
			c = 1'b0 ; 
          	d = 1'b0 ; 
          	f = 1'b0 ; 
          	g = 1'b0 ;
          
		end
  
  
  		4'b0101 : begin // A 
          	a = 1'b0 ;
			c = 1'b0 ; 
          	d = 1'b0 ; 
          	f = 1'b0 ; 
          	g = 1'b0 ;
          
		end
  
  		
  		4'b0101 : begin // B
          	a = 1'b0 ;
			c = 1'b0 ; 
          	d = 1'b0 ; 
          	f = 1'b0 ; 
          	g = 1'b0 ;
          
		end
  
  
  		4'b0101 : begin // C
          	a = 1'b0 ;
			c = 1'b0 ; 
          	d = 1'b0 ; 
          	f = 1'b0 ; 
          	g = 1'b0 ;
          
		end
  
  
  		4'b0101 : begin // D
          	a = 1'b0 ;
			c = 1'b0 ; 
          	d = 1'b0 ; 
          	f = 1'b0 ; 
          	g = 1'b0 ;
          
		end
  
  
  		4'b0101 : begin // E
          	a = 1'b0 ;
			c = 1'b0 ; 
          	d = 1'b0 ; 
          	f = 1'b0 ; 
          	g = 1'b0 ;
          
		end
  
  
		4'b0101 : begin // F
          	a = 1'b0 ;
			c = 1'b0 ; 
          	d = 1'b0 ; 
          	f = 1'b0 ; 
          	g = 1'b0 ;
          
		end
  
		endcase

end
  
endmodule
  		
  
  
 

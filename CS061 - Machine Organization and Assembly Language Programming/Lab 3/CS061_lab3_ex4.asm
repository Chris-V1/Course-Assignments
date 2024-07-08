;=================================================
; Name: Cristian Molano
; Email: cmola002@ucr.edu
; 
; Lab: LAB 1
; Lab section: 021
; TA: Shirin
; 
;=================================================
.ORIG x3000
	LD R2, DATA_PTR							
	LD R3, DEC_100							
	
	DO_WHILE
		LD R5, NEG_SENTINEL						
		GETC								
		OUT									
		STR R0, R2, #0						
		ADD R2, R2, #1						
		
		ADD R5, R5, R0							
		BRnp END_SENTINEL_CONDITION				
		
		SENTINEL_CONDITION
			AND R3, R3, x0						
		END_SENTINEL_CONDITION
		
		ADD R3, R3, #-1						
		BRp DO_WHILE						
	END_DO_WHILE
	
	LD R2, DATA_PTR						
	LD R3, DEC_100								
	LEA R0, newline
    PUTS
    
	DO_WHILE_2
		LD R5, NEG_SENTINEL					
		LDR R0, R2, #0						
		OUT									
		ADD R2, R2, #1						
		
		ADD R5, R5, R0							
		BRnp END_SENTINEL_CONDITION_2			
		
		SENTINEL_CONDITION_2
			AND R3, R3, x0						
		END_SENTINEL_CONDITION_2
		
		ADD R3, R3, #-1							
		BRp DO_WHILE_2						
	END_DO_WHILE_2
	
LEA R0, newline
PUTS	
	HALT										
	
	; Local data
	
	DEC_100 .FILL #100
	DATA_PTR .FILL x4000
	NEG_SENTINEL .FILL #-95
	newline .FILL x0A
	
	; Remote data
	.end
	.ORIG x4000
	ARRAY .BLKW #100
	
.END
;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Cristian Molano
; Email: cmola002@ucr.edu
; 
; Assignment name: Assignment 3
; Lab section: 021
; TA: Shirin
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team
; (apart from what was provided in the starter file).
;
;=========================================================================

.ORIG x3000			; Program begins here
;-------------
;Instructions
;-------------
LD R6, Value_ptr		; R6 <-- pointer to value to be displayed as binary
LDR R1, R6, #0			; R1 <-- value to be displayed as binary 
;-------------------------------
;INSERT CODE STARTING FROM HERE
;--------------------------------
LD R2, DEC_4
LOOP
LD R3, DEC_4
LOOP_2
LD R0, HEX_30
LD R5, EIGHTK
AND R5, R5, R1
BRn OUTPUT_1

OUTPUT_0
OUT
BR END_OUTPUT

OUTPUT_1
ADD R0,R0,#1
OUT
END_OUTPUT

ADD R1, R1, R1
ADD R3, R3, #-1
BRp LOOP_2
ADD R2, R2, #-1
BRz ENDING
LD R0, SPACE_CHAR
OUT
BR LOOP
ENDING
LD R0, newline           
OUT   
HALT
;---------------	
;Data
;---------------
Value_ptr	.FILL xCA01
HEX_30 .FILL x30
SPACE_CHAR .FILL x20
newline .FILL x0A
DEC_4 .FILL #4
EIGHTK .FILL x8000

.END

.ORIG xCA01				
Value .FILL xDCBA		
;---------------	
;END of PROGRAM
;---------------	
.END

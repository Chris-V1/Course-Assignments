;=================================================
; Name: Cristian Molano
; Email: cmola002@ucr.edu
; 
; Lab: LAB 1
; Lab section: 021
; TA: Shirin
; 
;=================================================
.orig x3000

LD R6, DATA_PTR
LD R5, DEC_10   ;so the loop runs 10 times

DO_WHILE
    GETC            ;GET CHARACTER
    OUT             ;output character
    ADD R1, R0, #0
    STR R1, R6, #0
    ADD R6, R6, #1
    ADD R5, R5, #-1
    BRp DO_WHILE
END_DO_WHILE

LD R5, DEC_10 ;give it 10 back
ADD R6, R6, #-10
LEA R0, newline
PUTS

DO_WHILE_2
    LDR R0, R6, #0
    OUT
    
    LEA R0, newline
    PUTS
    
    ADD R6, R6, #1
    ADD R5, R5, #-1
    BRp DO_WHILE_2
END_DO_WHILE_2
    
HALT


DATA_PTR .FILL X4000
DEC_10 .FILL #10
newline .FILL x0A
.END

.ORIG X4000
ARRAY .BLKW #10
.END
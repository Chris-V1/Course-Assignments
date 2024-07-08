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

LD R0, HEX_61
LD R1, HEX_1A

DO_WHILE_LOOP
OUT
ADD R0, R0, #1
ADD R1, R1, #-1
BRp DO_WHILE_LOOP

HALT

;DATA
HEX_61 .FILL x61
HEX_1A .FILL x1A

.END
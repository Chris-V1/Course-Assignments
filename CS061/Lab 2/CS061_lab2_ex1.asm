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

LD R3, DEC_65
LD R4, HEX_41

DEC_65 .FILL #65
HEX_41 .FILL x41
HALT
.END
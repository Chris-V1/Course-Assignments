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

LDI R3, DEC_65_PTR
LDI R4, HEX_41_PTR

ADD R3, R3, #1
ADD R4, R4, #1

STI R3, DEC_65_PTR
STI R4, HEX_41_PTR

HALT

DEC_65_PTR .FILL X4000
HEX_41_PTR .FILL X4001
.end
;; Remote data
.orig x4000
NEW_DEC_65 .FILL #65
NEW_HEX_41 .FILL x41

.END
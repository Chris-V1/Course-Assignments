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

LD R5, DEC_65_PTR
LD R6, HEX_41_PTR

LDR R3, R5, #0
LDR R4, R6, #0

ADD R3, R3, #1
ADD R4, R4, #1

STR R3, R5, #0
STR R4, R6, #0

HALT

DEC_65_PTR .FILL X4000
HEX_41_PTR .FILL X4001
.end
;; Remote data
.orig x4000
NEW_DEC_65 .FILL #65
NEW_HEX_41 .FILL x41

.END
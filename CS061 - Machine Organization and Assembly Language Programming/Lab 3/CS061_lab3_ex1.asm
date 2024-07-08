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

LD R5, DATA_PTR

LDR R3, R5, #0          ;DATA_PTR[0]
LDR R4, R5, #1          ;DATA-PTR[1]

ADD R3, R3, #1          ;R3 = R3+1
ADD R4, R4, #1          ;R4 = R4+1

STR R3, R5, #0          ;DATA_PTR[0] = R3
STR R4, R5, #1          ;DATA_PTR[1] = R4


HALT

DATA_PTR .FILL x4000

.end
;; Remote data
.orig x4000
NEW_DEC_65 .FILL #65
NEW_HEX_41 .FILL x41

.END
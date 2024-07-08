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
 LEA R0, MSG_TO_PRINT

 PUTS

 HALT

 MSG_TO_PRINT .STRINGZ "Hello World!!\n"

.END
;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Cristian Molano
; Email: cmola002@ucr.edu
; 
; Assignment name: Assignment 2
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

;----------------------------------------------
;output prompt
;----------------------------------------------	
LEA R0, intro			; get starting address of prompt string
PUTS; Invokes BIOS routine to output string

;-------------------------------
;INSERT YOUR CODE here
;-------------------------------------------------
;Part 1: Get the information and output the equation to the user
;-------------------------------------------------
GETC                                ;GET FIRST NUM
OUT                                 ;OUTPUT FIRST NUM
ADD R1, R0, #0                      ;PUT INTO R1

LD R0, newline                      ; LD copies the value stored at the address newline into R0	            
OUT                                 ; the TSR OUT writes the ascii code in R0 to console as a character

GETC                                ;GET SECOND NUM
OUT                                 ;OUTPUT SECOND NUM
ADD R2, R0, #0                      ;PUT INTO R2

LD R0, newline                      ; LD copies the value stored at the address newline into R0	            
OUT                                 ; the TSR OUT writes the ascii code in R0 to console as a character

                                    ;Writing the equation:
ADD R0, R1, #0                      ;Put R1 onto R0
OUT                                 ;Output R0 (R1)
LEA R0, subtraction                 ;Put subtraction string onto R0
PUTS                                ;Output R0 (subtraction string)
ADD R0, R2, #0                      ;Put R2 onto R0
OUT                                 ;Output R0 (R2)
LEA R0, equals                      ;Put Equals string onto R0
PUTS                                ;Output R0 (equals string)

;-------------------------------------------------
;Part 2: Computation and Results
;-------------------------------------------------

LD R4, HEX_30                       ;48 in R4
NOT R4, R4                          ;negate r4
ADD R4, R4, #1                      ;add 1 for twos complement
ADD R5, R1, R4                      ;r5 = r1-48
ADD R3, R2, R4                      ;r3 = r2-48
NOT R3, R3                          ;negate r3
ADD R3, R3, #1                      ;add 1 for twos complement (again)
ADD R6,R5,R3                        ;r6 = r5 + r3
NOT R4,R4                           ;negate r4
ADD R4,R4, #1                       ;add 1 for twos complement (once again)

;-------------------------------------------------
;Part 2: Seeing if the result is negative and output
;-------------------------------------------------
ADD R6,R6, #0                       ;checker equation
BRzp negative                       ;if negative, move on, else skip to the next "negative" (this is an if statement equivalent)
NOT R6, R6                          ;negate R6
ADD R6, R6, #1                      
ADD R6, R6, R4
LEA R0, neg                         ;output negative sign
PUTS
ADD R0, R6, #0                      ;output number w/negative sign
OUT
LD R0, newline                      ; LD copies the value stored at the address newline into R0	            
OUT                                 ; the TSR OUT writes the ascii code in R0 to console as a character
HALT
negative                            ;ending of the loop
ADD R0, R6, #0
OUT
LD R0, newline                      ; LD copies the value stored at the address newline into R0	            
OUT                                 ; the TSR OUT writes the ascii code in R0 to console as a character


HALT				                ; Stop execution of program
;------	
;Data
;------
; String to prompt user. Note: already includes terminating newline!
intro 	            .STRINGZ	"ENTER two numbers (i.e '0'....'9')\n" 		; prompt string - use with LEA, followed by PUTS.
subtraction         .STRINGZ    " - "
equals              .STRINGZ    " = "
neg                 .STRINGZ    "-"
newline             .FILL x0A	                                            ; newline character - use with LD followed by OUT
HEX_30              .FILL X30
;---------------	
;END of PROGRAM
;---------------	
.END


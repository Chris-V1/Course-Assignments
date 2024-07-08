;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Cristian Molano
; Email: cmola002@ucr.edu
; 
; Assignment name: Assignment 4
; Lab section: 021
; TA: Shirin
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team
; (apart from what was provided in the starter file).
;
;=========================================================================
;THE BINARY REPRESENTATION OF THE USER-ENTERED DECIMAL VALUE MUST BE STORED IN REGISTER 4 (R4)
;=================================================================================

.ORIG x3000		
;-------------
;Instructions
;-------------

; output intro prompt
LD R0, introPromptPtr 
PUTS

LOOP1
LD R1, DEC_10
NOT R1, R1
ADD R1, R1, #1

LEA R0, newline
OUT

GETC ;GET THE NEXT CHARACTER
OUT

IF1 ;CHECK FOR VALID INPUTS
    ADD R1, R1, R0
    BRz WRONG_INPUT
    BRnp CORRECT

CORRECT
    LD R1, DEC_0
    LD R4, NEG
    NOT R4, R4
    ADD R4, R4, #1
    ADD R2, R0, #0
    ADD R3, R4, R2
    BRz NEGATIVE
    BRn POSITIVE
    BRp NEXT_STEP
    
NEGATIVE
    GETC
    OUT
    LD R4, DEC_1
    IF2
        LD R6, ASCII
        NOT R6, R6
        ADD R6, R6, #1
        ADD R0,R0,R6
        BRn WRONG_INPUT
        BRzp NEXT_STEP2
        
POSITIVE
    GETC
    OUT
    LD R4, DEC_0
    IF3
        LD R6, ASCII
        NOT R6, R6
        ADD R6, R6, #1
        ADD R0, R0, R6
        BRn WRONG_INPUT
        BRzp NEXT_STEP3
        
NEXT_STEP
    LD R6, ASCII
    NOT R6, R6
	ADD R6, R6, #1
	ADD R1, R0, R6
	LD R4, DEC_0
    BRzp NEXT_STEP3

NEXT_STEP2
    LD R4, DEC_1
    BRp NEXT_STEP3
    
NEXT_STEP3
    LD R5, DEC_57
    NOT R5, R5
    ADD R5, R5, #1
    ADD R3, R5, R2
    BRp WRONG_INPUT
    BRnz NEXT_STEP4

NEXT_STEP4
    ADD R1, R0, R1
    ADD R1, R1, R6
    BRp NEXT1
    BRnz NEXT2
    
NEXT1
    ADD R1, R0, R6
    BRp NEXT_STEP5

NEXT2
    NOT R6, R6
	ADD R6, R6, #1
	ADD R1, R1, R6
	NOT R6, R6
	ADD R6, R6, #1
	BRp NEXT_STEP5

NEXT_STEP5
    LOOP2
        GETC
        OUT
        IF4
            ADD R3, R0, R5
            BRp WRONG_INPUT1
            BRnz NEXT_STEP6

NEXT_STEP6
    LD R2, newline ;equivalent of enter
    NOT R2, R2
    ADD R2, R2, #1
    ADD R3, R2, R0
    BRp NEXT_STEP7
    BRz STOP

NEXT_STEP7
    LD R6, ASCII
    NOT R6, R6
    ADD R6, R6, #1
    ADD R0, R0, R6
    LD R6, DEC_9
    ADD R3, R1, #0
    LOOP3
        ADD R3, R1, R3
        ADD R6, R6, #-1
        BRp LOOP3
        END_LOOP3
        ADD R1, R3, R0
        LD R6, DEC_9
    BRp LOOP1

STOP
    END_LOOP1
    END_LOOP2
    
    IF5
        ADD R4, R4, #0
        BRz NO
        BRp YES

YES
    NOT R1, R1
    ADD R1, R1, #1
    BRz NO

WRONG_INPUT
    LEA R0, newline
    OUT
    LEA R0, eR4orMessagePtr
    PUTS
    LEA R0, newline
    ADD R0, R0, #0
    BRnzp LOOP1

WRONG_INPUT1
    LEA R0, newline
    OUT
    LEA R0, eR4orMessagePtr
    PUTS
    LEA R0, newline
    LD R0, DEC_9
    BRp LOOP1


NO


HALT




; Set up flags, counters, accumulators as needed

; Get first character, test for '\n', '+', '-', digit/non-digit 	

; is very first character = '\n'? if so, just quit (no message)!

; is it = '+'? if so, ignore it, go get digits

; is it = '-'? if so, set neg flag, go get digits
					
; is it < '0'? if so, it is not a digit	- o/p eR4or message, start over

; is it > '9'? if so, it is not a digit	- o/p eR4or message, start over
				
; if none of the above, first character is first numeric digit - convert it to number & store in target register!
					
; Now get remaining digits from user in a loop (max 5), testing each to see if it is a digit, and build up number in accumulator

; remember to end with a newline!
					


;---------------	
; Program Data
;---------------

introPromptPtr  .FILL xB000
eR4orMessagePtr .FILL xB200

DEC_0 .FILL #0
DEC_1 .FILL #1
DEC_9 .FILL #9
DEC_10 .FILL #10
DEC_57 .FILL #57

NEG .FILL x20
ASCII .FILL x30
newline .FILL x0A


.END

;------------
; Remote data
;------------
.ORIG xB000	 ; intro prompt
.STRINGZ	 "Input a positive or negative decimal number (max 5 digits), followed by ENTER\n"

.END					
					
.ORIG xB200	 ; eR4or message
.STRINGZ	 "ER4OR: invalid input\n"

;---------------
; END of PROGRAM
;---------------
.END


;-------------------
; PURPOSE of PROGRAM
;-------------------
; Convert a sequence of up to 5 user-entered ascii numeric digits into a 16-bit two's complement binary representation of the number.
; if the input sequence is less than 5 digits, it will be user-terminated with a newline (ENTER).
; Otherwise, the program will emit its own newline after 5 input digits.
; The program must end with a *single* newline, entered either by the user (< 5 digits), or by the program (5 digits)
; Input validation is performed on the individual characters as they are input, but not on the magnitude of the number.

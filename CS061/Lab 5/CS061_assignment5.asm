;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Cristian Molano
; Email: cmola002@ucr.edu
; 
; Assignment name: Assignment 5
; Lab section: 021
; TA: Shirin
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team
; (apart from what was provided in the starter file).
;
;=========================================================================
; PUT ALL YOUR CODE AFTER THE main LABEL, FOLLOW LAB MANUAL FOR BEST RESULTS.
;=================================================================================

;---------------------------------------------------------------------------------
;  Initialize program by setting stack pointer and calling main subroutine
;---------------------------------------------------------------------------------
.ORIG x3000

; initialize the stack
ld r6, stack_addr

; call main subroutine
lea r5, main
jsrr r5

;---------------------------------------------------------------------------------
; Main Subroutine
;---------------------------------------------------------------------------------
main
; get a string from the user
; * put your code here
LD R2, get_user_string_addr
JSRR R2
; find size of input string
; * put your code here
LD R3, strlen_addr
JSRR R3
; call palindrome method
; * put your code here

; determine of stirng is a palindrome
; * put your code here

; print the result to the screen
; * put your code here

; decide whether or not to print "not"
; * put your code here


HALT

;---------------------------------------------------------------------------------
; Required labels/addresses
;---------------------------------------------------------------------------------

; Stack address ** DO NOT CHANGE **
stack_addr           .FILL    xFE00

; Addresses of subroutines, other than main
get_user_string_addr .FILL    x3200
strlen_addr          .FILL    x3300
palindrome_addr      .FILL	  x3400


; Reserve memory for strings in the progrtam
user_prompt          .STRINGZ "Enter a string: "
result_string        .STRINGZ "The string is "
not_string           .STRINGZ "not "
final_string         .STRINGZ	"a palindrome\n"

; Reserve memory for user input string
user_string          .BLKW	  100

.END

;---------------------------------------------------------------------------------
; get_user_string - gets the string from the user
;
; doesnt return anything
;---------------------------------------------------------------------------------
.ORIG x3200
get_user_string
; Backup all used registers, R7 first, using proper stack discipline

;backup
ST R7, BACKUP_R7_3200
ST R0, BACKUP_R0_3200
ST R1, BACKUP_R1_3200
ST R2, BACKUP_R2_3200
ST R3, BACKUP_R3_3200
ST R4, BACKUP_R4_3200
ST R5, BACKUP_R5_3200
ST R6, BACKUP_R6_3200
		

;write entry prompt and output it



LEA R0, entry_prompt
PUTS

LEA r1, INPUT       ; r1 = address of input


PROMPT
    TRAP x20            ; getc, r0 = character input
    TRAP x21
    
    STR r0, r1, #0      ; mem[r1 + INPUT] = r0
    ADD r1, r1, #1      ; r1 = r1 + 1
    ADD r0, r0, #-10    ; r0 = r0 - new line
    BRnp PROMPT         ; branch if r0 != 0
    




LD R7, BACKUP_R7_3200
LD R0, BACKUP_R0_3200
LD R1, BACKUP_R1_3200
LD R2, BACKUP_R2_3200
LD R3, BACKUP_R3_3200
LD R4, BACKUP_R4_3200
LD R5, BACKUP_R5_3200
LD R6, BACKUP_R6_3200

RET

;DEC_0 .FILL #0

INPUT .BLKW 64


; Resture all used registers, R7 last, using proper stack discipline
BACKUP_R0_3200 .BLKW #1
BACKUP_R1_3200 .BLKW #1
BACKUP_R2_3200 .BLKW #1
BACKUP_R3_3200 .BLKW #1
BACKUP_R4_3200 .BLKW #1
BACKUP_R5_3200 .BLKW #1
BACKUP_R6_3200 .BLKW #1
BACKUP_R7_3200 .BLKW #1

entry_prompt .STRINGZ "Enter a string: "


; main
    .FILL xE20A

; prompt
    .FILL xF020
    .FILL x7040
    .FILL x1261
    .FILL x1036
    .FILL x0BFB

; end
    .FILL x127F
    .FILL x7040
    .FILL xE002

    .FILL xF022
    .FILL xF025

; data
.BLKW 64

.END

;---------------------------------------------------------------------------------
; strlen - compute the length of a zero terminated string
;
; parameter: R1 - the address of a zero terminated string
;
; returns: The length of the string
;-------
.ORIG x3300
strlen
; Backup all used registers, R7 first, using proper stack discipline
ST R7, BACKUP_R7_3400
ST R0, BACKUP_R0_3400
ST R1, BACKUP_R1_3400
ST R2, BACKUP_R2_3400
ST R3, BACKUP_R3_3400
ST R4, BACKUP_R4_3400
ST R5, BACKUP_R5_3400
ST R6, BACKUP_R6_3400
; Resture all used registers, R7 last, using proper stack discipline

LEA R1, INPUT
lea r0, INPUT
PUTS

    ADD r1, r1, #-1     ; subtract one from r1
    STR r0, r1, #0      ; mem[r1 + INPUT] = r0 (which is zero)
    LEA r0, INPUT       ; r0 = address of input

    TRAP x22            ; puts, display string
    TRAP x25            ; halt



LD R7, BACKUP_R7_3400
LD R0, BACKUP_R0_3400
LD R1, BACKUP_R1_3400
LD R2, BACKUP_R2_3400
LD R3, BACKUP_R3_3400
LD R4, BACKUP_R4_3400
LD R5, BACKUP_R5_3400
LD R6, BACKUP_R6_3400
RET

BACKUP_R0_3400 .BLKW #1
BACKUP_R1_3400 .BLKW #1
BACKUP_R2_3400 .BLKW #1
BACKUP_R3_3400 .BLKW #1
BACKUP_R4_3400 .BLKW #1
BACKUP_R5_3400 .BLKW #1
BACKUP_R6_3400 .BLKW #1
BACKUP_R7_3400 .BLKW #1


.END

;---------------------------------------------------------------------------------
; palindrome - DO NOT FORGET TO REPLACE THIS HEADER WITH THE PROPER HEADER
;---------------------------------------------------------------------------------
.ORIG x3400
palindrome ; Hint, do not change this label and use for recursive alls
; Backup all used registers, R7 first, using proper stack discipline

; Resture all used registers, R7 last, using proper stack discipline
.END

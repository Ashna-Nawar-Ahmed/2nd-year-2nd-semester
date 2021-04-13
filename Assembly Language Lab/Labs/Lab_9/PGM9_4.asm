.MODEL SMALL
.STACK 100H
.CODE
MAIN PROC  
    ;input a number
    CALL INDEC
    PUSH AX
    ;move cursor to a new line
    MOV AH,2
    MOV DL,0DH
    INT 21H
    MOV DL,0AH
    INT 21H
    ;output the number
    POP AX
    CALL OUTDEC
    ;dos exit
    MOV AH,4CH
    INT 21H
    MAIN ENDP
    INCLUDE PGM9_1.ASM
    INCLUDE PGM9_3.ASM 
    END MAIN
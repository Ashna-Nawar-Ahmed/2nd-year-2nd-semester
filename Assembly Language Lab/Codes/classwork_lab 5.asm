.MODEL SMALL
.STACK 100H 
.DATA
VAL DW ?
.CODE
MAIN PROC 
    MOV AX,@DATA
    MOV DS,AX
    
    
    MOV AL,'A' 
    MOV BL,'C'
    
    CMP BL,AL
    JG AL_GREATER
    JL BL_GREATER
    
    AL_GREATER:
    MOV DL,AL
    MOV AH,2
    INT 21H
    JMP END
    
    BL_GREATER:
    MOV DL,BL
    MOV AH,2
    INT 21H
    JMP END
    
    END:
    
    MOV AH,4CH
    INT 21H
    END MAIN
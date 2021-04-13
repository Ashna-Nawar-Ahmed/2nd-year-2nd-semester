.MODEL SMALL
.STACK 100H
.DATA 
MSG1 DW 0AH,0DH,'A=$'
MSG2 DW 0AH,0DH,'B=$'
MSG3 DW 0AH,0DH,'C=$'
A DB ?
B DB ?
C DB ?
.CODE
MAIN PROC
    ;INITIALIZATION
    MOV AX,@DATA
    MOV DS,AX
    
    ;B=2
    MOV AL,2
    MOV B,AL
    
    ;A=5-2B
    MOV AL,5
    SUB AL,B
    SUB AL,B
    ADD AL,48
    MOV A,AL
    
    ;C=2A+2B
    MOV AL,A
    ADD AL,B
    ADD AL,AL
    SUB AL,48
    MOV C,AL
    
    ;OUTPUT A
    LEA DX,MSG1
    MOV AH,9
    INT 21H
    
    MOV DL,A
    MOV AH,2
    INT 21H
    
    ;OUTPUT B
    
    LEA DX,MSG2
    MOV AH,9
    INT 21H
    
    ADD B,48
    MOV DL,B
    MOV AH,2
    INT 21H
    
    ;OUTPUT C
    LEA DX,MSG3
    MOV AH,9
    INT 21H
    
    MOV DL,C
    MOV AH,2
    INT 21H
    
    ;TERMINATION
    MOV AX,4C00H
    INT 21H
    
    END MAIN
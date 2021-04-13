.MODEL SMALL
.STACK 100H 
.DATA
STR1 DB 'ENTER A CHARACTER: $',0AH,0DH 
STR2 DB 0AH,0DH,'NUMBER OF 1 BITS:$'
CHAR DB ? 
VAL DB 0
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS,AX 
    
    ;PRINT STR1
    LEA DX,STR1
    MOV AH,9
    INT 21H
    
    ;TAKE INPUT
    MOV AH,1
    INT 21H
    MOV CHAR,AL
    AND AL,0FFH
    
    ;NEWLINE
    MOV DL,0AH
    MOV AH,2
    INT 21H
    MOV DL,0DH
    INT 21H
    
    
    ;CONVERT TO BINARY
    XOR BX,BX  
    MOV CX,0
    MOV AH,2  
    MOV BL,CHAR
    START_CONVERT:
    MOV DL,VAL 
    CMP DL,8
    JE NEXT
    SHL BL,1
    JC ONE 
    JMP ZERO
    
    ONE:
    MOV DL,'1' 
    INC CX
    JMP PRINT 
    
    ZERO:
    MOV DL,'0'
    JMP PRINT
    
    PRINT:
    INT 21H 
    INC VAL
    JMP START_CONVERT  
    
    NEXT:
    ;PRINT STR2
    LEA DX,STR2
    MOV AH,9
    INT 21H  
    
    
    MOV DL,CL
    OR DL,30H
    MOV AH,2
    INT 21H
    
    END:
    MOV AH,4CH
    INT 21H
    END MAIN
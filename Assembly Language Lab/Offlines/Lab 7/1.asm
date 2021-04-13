.MODEL SMALL
.STACK 100H


.DATA
STR DB "ENTER A CHARACTER: $"
STR2 DB 0AH,0DH, "BINARY CODE:$" 
STR3 DB 0AH,0DH, "NUMBER OF 1:$" 

.CODE

MAIN PROC
    
    MOV AX, @DATA
    MOV DS,AX
    
    LEA DX,STR
    MOV AH,9
    INT 21H
    
    ;TAKE INPUT
    MOV AH,1
    INT 21H
    MOV BL,AL
     
    LEA DX,STR2
    MOV AH,9
    INT 21H
    
    MOV CX,8
    MOV BH,0
    TOP:
        ROL BL,1
        JNC NEXT
        
        MOV DL,'1'
        MOV AH,2
        INT 21H
        INC BH
        JMP LOP
        
    NEXT:
        MOV DL,'0'
        MOV AH,2
        INT 21H
    LOP:
        LOOP TOP
    
    LEA DX,STR3
    MOV AH,9
    INT 21H
    
    ADD BH,48
    MOV DL,BH
    MOV AH,2
    INT 21H
    
    MOV AH,4CH
    INT 21H
    END MAIN
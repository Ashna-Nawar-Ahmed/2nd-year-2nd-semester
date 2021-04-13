.MODEL SMALL
.STACK 100H
.DATA
STR DW 0AH,0DH,'**********$'
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    LEA DX,STR
    MOV AH,9
    INT 21H 
    
    LEA DX,STR
    MOV AH,9
    INT 21H
    
    LEA DX,STR
    MOV AH,9
    INT 21H
    
    LEA DX,STR
    MOV AH,9
    INT 21H
    
    LEA DX,STR
    MOV AH,9
    INT 21H
    
    LEA DX,STR
    MOV AH,9
    INT 21H
    
    LEA DX,STR
    MOV AH,9
    INT 21H
    
    LEA DX,STR
    MOV AH,9
    INT 21H
    
    LEA DX,STR
    MOV AH,9
    INT 21H
    
    LEA DX,STR
    MOV AH,9
    INT 21H
    
    MOV AH,4CH
    INT 21H
    END MAIN
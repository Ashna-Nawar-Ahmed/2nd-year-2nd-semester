.MODEL SMALL
.STACK 100H
.DATA
D DB 080H
SPACE DB ' $' 
COUNT DB 0
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX  
       
    TOP: 
    MOV CL,D
    CMP CL,0FFH
    JG END 
    MOV DL,CL
    MOV AH,2
    INT 21H 
    LEA DX,SPACE
    MOV AH,9
    INT 21H
    INC CL  
    MOV D,CL 
    INC COUNT
    MOV CL,COUNT
    CMP CL,9
    JG NEWLINE
    JMP TOP
    
    NEWLINE:
    MOV DL,0AH
    MOV AH,2
    INT 21H
    MOV DL,0DH
    INT 21H 
    MOV COUNT,0
    JMP TOP
    
    END:
    MOV AH,4CH
    INT 21H
    END MAIN
   
.MODEL SMALL
.STACK 100H
.DATA
ARRAY DB 'A','S','H','N','A'
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV DL,ARRAY[4]
    MOV AH,2
    INT 21H 
    
    MOV DL,ARRAY[3]
    MOV AH,2
    INT 21H
    
    MOV DL,ARRAY[2]
    MOV AH,2
    INT 21H
    
    MOV DL,ARRAY[1]
    MOV AH,2
    INT 21H
    
    MOV DL,ARRAY[0]
    MOV AH,2
    INT 21H 
    
    MOV AH,4CH
    INT 21H
    END MAIN
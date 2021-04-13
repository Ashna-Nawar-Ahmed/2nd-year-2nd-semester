.MODEL SMALL
.STACK 100H
.DATA
STR1 DW 0AH,0DH,'***********$'  
STR DW 0AH,0DH,'*         *$'  
STR2 DW 0AH,0DH,'*   $' 
STR3 DW '   *$'
CHAR DB '?#'
F DB ?
M DB ?
L DB ?
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ;? OUTPUT
    MOV DL,CHAR
    MOV AH,2
    INT 21H   
    
    ;F INPUT
    MOV AH,1
    INT 21H
    MOV F,AL 
    
    ;M INPUT
    MOV AH,1
    INT 21H
    MOV M,AL
    
    ;L INPUT
    MOV AH,1
    INT 21H
    MOV L,AL
    
    ;1
    LEA DX,STR1
    MOV AH,9
    INT 21H 
    
    ;2
    LEA DX,STR
    MOV AH,9
    INT 21H
    
    ;3
    LEA DX,STR
    MOV AH,9
    INT 21H
    
    ;4
    LEA DX,STR
    MOV AH,9
    INT 21H
    
    ;5
    LEA DX,STR
    MOV AH,9
    INT 21H
    
    ;6_1
    LEA DX,STR2
    MOV AH,9
    INT 21H
    
    ;F OUTPUT
    MOV DL,F
    MOV AH,2
    INT 21H
     
    ;M OUTPUT
    MOV DL,M
    MOV AH,2
    INT 21H
    
    ;L OUTPUT
    MOV DL,L
    MOV AH,2
    INT 21H
    
    ;6_2
    LEA DX,STR3
    MOV AH,9
    INT 21H
    
    ;7
    LEA DX,STR
    MOV AH,9
    INT 21H
    
    ;8
    LEA DX,STR
    MOV AH,9
    INT 21H
    
    ;9
    LEA DX,STR
    MOV AH,9
    INT 21H
    
    ;10
    LEA DX,STR
    MOV AH,9
    INT 21H 
    
    ;11
    LEA DX,STR1
    MOV AH,9
    INT 21H  
    
    ;beep
    MOV DL,7
    MOV AH,2
    INT 21H
    
    MOV AH,4CH
    INT 21H
    END MAIN
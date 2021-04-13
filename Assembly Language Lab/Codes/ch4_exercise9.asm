.MODEL SMALL
.STACK 100H
.DATA 
MSG DW 'ENTER THREE INITIALS:$'
F DB ?
M DB ?
L DB ?
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ;OUTPUT MSG
    LEA DX,MSG
    MOV AH,9
    INT 21H
    
    ;INPUT F
    MOV AH,1
    INT 21H
    MOV F,AL  
    
    ;INPUT M
    MOV AH,1
    INT 21H
    MOV M,AL
    
    ;INPUT L
    MOV AH,1
    INT 21H
    MOV L,AL
    
    ;NEWLINE
    MOV DL,0AH
    MOV AH,2
    INT 21H  
    MOV DL,0DH
    MOV AH,2
    INT 21H
    
    ;OUTPUT F
    MOV DL,F
    MOV AH,2
    INT 21H 
    
    ;NEWLINE
    MOV DL,0AH
    MOV AH,2
    INT 21H  
    MOV DL,0DH
    MOV AH,2
    INT 21H
    
    ;OUTPUT M
    MOV DL,M
    MOV AH,2
    INT 21H  
    
    ;NEWLINE
    MOV DL,0AH
    MOV AH,2
    INT 21H  
    MOV DL,0DH
    MOV AH,2
    INT 21H
    
    ;OUTPUT L
    MOV DL,L
    MOV AH,2
    INT 21H  
    
    MOV AH,4CH
    INT 21H
    END MAIN
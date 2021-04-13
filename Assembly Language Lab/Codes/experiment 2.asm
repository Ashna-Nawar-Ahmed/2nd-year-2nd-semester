.MODEL SMALL
.STACK 100H
.DATA
MSGA DW 'Enter character to be displayed$'
MSGB DW 'Entered character:$' 
 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ;PRINTING PROMPT
    LEA DX,MSGA
    MOV AH,9
    INT 21H
    
    ;PRINTING NEW LINE
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H  
    
    ;TAKING INPUT A CHARACTER
    MOV AH,1
    INT 21H
    MOV BL,AL
    
    
    ;NEW LINE
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
    
    ;PRINTING NEW PROMPT
    LEA DX,MSGB
    MOV AH,9
    INT 21H 
    
    MOV AH,2
    MOV DL,BL
    INT 21H
    
    MOV AH,4CH
    INT 21H
    
    END MAIN
    
    
    
    
    
.MODEL SMALL
.STACK 100H
.DATA 
MSG DW 'ENTER  HEX DIGIT:$'  
MSG1 DW 0AH,0DH,'IN DECIMAL IT IS:1$'
HEX DB ?
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    
    MOV AH,9 
    LEA DX,MSG
    INT 21H
    
    MOV AH,1
    INT 21H  
    
    MOV HEX,AL
    SUB HEX,11H 
    
    
    MOV AH,9
    LEA DX,MSG1
    INT 21H
    
    
    MOV AH,2 
    MOV DL,HEX
    INT 21H
    
    MOV AH,4CH
    INT 21H
    END MAIN
.MODEL SMALL
.STACK 100H
.DATA
MSG1 DB 'ENTER FIRST DIGIT:$'
MSG2 DB 0DH,0AH,'ENTER SECOND DIGIT:$'
MSG3 DB 0DH,0AH,'FIRST DIGIT IS:$'
MSG4 DB 0DH,0AH,'SECOND DIGIT IS:$'  
MSG5 DB 0DH,0AH,'SUM IS:$'
A DB ?
B DB ?
SUM DB ?

.CODE
MAIN PROC 
    ;initialization
    MOV AX,@DATA
    MOV DS,AX     
    
    ;print MSG1
    LEA DX,MSG1
    MOV AH,9
    INT 21H
    
    ;input A
    MOV AH,1
    INT 21H
    MOV A,AL  
    
    ;print MSG2
    LEA DX,MSG2
    MOV AH,9
    INT 21H
    
    ;input B
    MOV AH,1
    INT 21H
    MOV B,AL 
    
    ;SUM
    MOV AL,A
    ADD AL,B
    SUB AL,48
    MOV SUM,AL
    
    ;print MSG3
    LEA DX,MSG3
    MOV AH,9
    INT 21H     
    
    ;print A
    MOV DL,A
    MOV AH,2
    INT 21H
    
    ;print MSG4
    LEA DX,MSG4
    MOV AH,9
    INT 21H     
    
    ;print B
    MOV DL,B
    MOV AH,2
    INT 21H  
    
    ;print MSG5
    LEA DX,MSG5
    MOV AH,9
    INT 21H     
    
    ;print SUM
    MOV DL,SUM
    MOV AH,2
    INT 21H                          
                                
    ;termination                         
    MOV AH,4CH
    INT 21H
    END MAIN
  
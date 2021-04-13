.MODEL SMALL
.STACK 100H
.DATA
    MSG1 DB "Enter the value of M: $"
    MSG2 DB 0DH,0AH,"Enter the value of N: $"
    MSG3 DB 0DH,0AH,"GCD: $"
 
.CODE
MAIN PROC
    MOV AX, @DATA                
    MOV DS, AX

    LEA DX, MSG1           
    MOV AH, 9
    INT 21H

    CALL INDEC                   
                                 
    PUSH AX                      
                                 
    LEA DX, MSG2             
    MOV AH, 9
    INT 21H

    CALL INDEC                   

    MOV BX, AX                   

    POP AX                       
     
    REPEAT:                     
    XOR DX, DX                 
    DIV BX                     
    CMP DX, 0                  
    JE END1

    MOV AX, BX                 
    MOV BX, DX                 
    JMP REPEAT                  

    END1:                   

    LEA DX, MSG3        
    MOV AH, 9
    INT 21H

    MOV AX, BX              

    CALL OUTDEC 
                   

    MOV AH, 4CH   
    INT 21H
    MAIN ENDP
  INCLUDE INDEC.ASM
  INCLUDE OUTDEC.ASM
END MAIN
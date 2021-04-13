.MODEL SMALL
.STACK 100H
.DATA
    MSG1 DB "Enter the time in seconds up to 65535 = $"
    MSG2 DB 0DH,0AH,"The time in hh:mm:ss format is = $"  
    HOUR DB " hours $"
    MIN DB " minute $"
    SEC DB " second $"

.CODE
MAIN PROC
    MOV AX,DATA                
    MOV DS,AX

    LEA DX,MSG1             
    MOV AH,9
    INT 21H

    CALL INDEC                   

    PUSH AX                      

    LEA DX,MSG2                
    MOV AH,9
    INT 21H

    POP AX                       
    XOR DX,DX                   
    MOV CX,3600                  
    DIV CX                       
    CMP AX,10                   
    JGE HOURS                   

    PUSH AX                     

    MOV AX,0                    
    CALL OUTDEC                  

    POP AX                       
                                   
    HOURS:                     
    CALL OUTDEC                  

    MOV AX,DX                   

    PUSH AX                     

    LEA DX,HOUR         
    MOV AH,9
    INT 21H

    POP AX                      
    XOR DX,DX                   
    MOV CX,60                   
    DIV CX                      

    CMP AX,10                   
    JGE MINUTES                 

    PUSH AX                     

    MOV AX,0                    
    CALL OUTDEC                 

    POP AX                      

    MINUTES:                    
    CALL OUTDEC                 

    MOV BX,DX                   

    LEA DX,MIN            
    MOV AH, 9
    INT 21H

    MOV AX, BX            

    CMP AX, 10                   
    JGE SECONDS                 
    PUSH AX                       

    MOV AX, 0                    
    CALL OUTDEC                  

    POP AX                       

    SECONDS:                    
    CALL OUTDEC
    
    LEA DX,SEC         
    MOV AH,9
    INT 21H            

    MOV AH, 4CH        
    INT 21H
  MAIN ENDP 
  
  INCLUDE INDEC.ASM      
  INCLUDE OUTDEC.ASM
END MAIN
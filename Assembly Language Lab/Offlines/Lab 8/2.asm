.MODEL SMALL
.STACK 100H

.DATA
   MSG DB 0DH,0AH,'ENTER AN ALGEBRAIC EXPRESSION: ',0DH,0AH,'$'
   CORRECTEXP DB 0DH,0AH,'EXPRESSION IS CORRECT.$'
   LEFTBRACKETCNT DB 0DH,0AH,'TOO MANY LEFT BRACKETS.$'
   RIGHTBRACKETCNT DB 0DH,0AH,'TOO MANY RIGHT BRACKETS.$'
   MISMATCHMSG DB 0DH,0AH,'BRACKETS DONT MATCH! TRY AGAIN.$'
   CONTINUEMSG DB 0DH,0AH,'TYPE Y TO CONTINUE: $'
              
.CODE
   MAIN PROC    
     MOV AX, @DATA                
     MOV DS, AX

     @START:                      
     LEA DX, MSG               
     MOV AH, 9
     INT 21H

     XOR CX, CX                   

     MOV AH, 1                    

     @INPUT:                      
       INT 21H                    

       CMP AL, 0DH                
       JE @END_INPUT             

       CMP AL, "["                
       JE @PUSH_BRACKET           

       CMP AL, "{"                
       JE @PUSH_BRACKET           

       CMP AL, "("                
       JE @PUSH_BRACKET           

       CMP AL, ")"                
       JE @FIRST_BRACKET          
                                   
       CMP AL, "}"                
       JE @SECOND_BRACKET          

       CMP AL, "]"                
       JE @THIRD_BRACKET         

       JMP @INPUT                 

       @PUSH_BRACKET:             

       PUSH AX                    
       INC CX                     
       JMP @INPUT                 

       @FIRST_BRACKET:            

       POP DX                     
       DEC CX                     

       CMP CX, 0                  
       JL @RIGHTBRACKETCNT         

       CMP DL, "("                
       JNE @MISMATCH              
       JMP @INPUT                 
       
       @SECOND_BRACKET :            

       POP DX                     
       DEC CX                     

       CMP CX, 0                  
       JL @RIGHTBRACKETCNT         

       CMP DL, "{"                
       JNE @MISMATCH              
       JMP @INPUT                 

       @THIRD_BRACKET:           
                                   
       POP DX                     
       DEC CX                     

       CMP CX, 0                  
       JL @RIGHTBRACKETCNT         

       CMP DL, "["                
       JNE @MISMATCH              
     JMP @INPUT                   

     @END_INPUT:                  

     CMP CX, 0                    
     JNE @LEFTBRACKETCNT           

     MOV AH, 9                    

     LEA DX, CORRECTEXP              
     INT 21H                      

     LEA DX, CONTINUEMSG             
     INT 21H                       

     MOV AH, 1                    
     INT 21H                      

     CMP AL, "Y"                  
     JNE @EXIT                    
     JMP @START                   

     @MISMATCH:                   

     LEA DX,MISMATCHMSG             
     MOV AH, 9                     
     INT 21H

     JMP @START                   

     @LEFTBRACKETCNT:              

     LEA DX, LEFTBRACKETCNT        
     MOV AH, 9
     INT 21H

     JMP @START                   

     @RIGHTBRACKETCNT:             

     LEA DX, RIGHTBRACKETCNT       
     MOV AH, 9
     INT 21H

     JMP @START                   

     @EXIT:                       

     MOV AH, 4CH                  
     INT 21H
   MAIN ENDP
 END MAIN
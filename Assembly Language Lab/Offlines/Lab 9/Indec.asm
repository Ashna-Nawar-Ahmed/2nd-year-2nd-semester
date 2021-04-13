INDEC PROC
    
    PUSH BX
    PUSH CX
    PUSH DX
    
    BEGIN:  
    XOR BX,BX
    
    XOR CX,CX
    
    MOV AH,1
    INT 21H
    
    CMP AL,'-'
    JE MINUS
    CMP AL,'+'
    JE PLUS
    JMP REPEAT2
    MINUS:
    MOV CX,1
    PLUS:
    INT 21H
    
    REPEAT2:

    CMP AL,'0'
    JNGE NOT_DIGIT
    CMP AL,'9'
    JNLE NOT_DIGIT
    
    AND  AX,000FH
    PUSH AX
    
    MOV AX,10
    MUL BX
    POP BX
    ADD BX,AX
    
    MOV AH,1 
    INT 21H
    CMP AL,0DH
    JNE REPEAT2
    
    MOV AX,BX
    
    OR CX,CX
    JE EXIT
    
    NEG AX
    
    EXIT:
    POP DX
    POP CX
    POP BX
    RET
    
    NOT_DIGIT:
    MOV AH,2
    MOV DL,0DH
    INT 21H
    MOV DL,0AH
    INT 21H
    JMP BEGIN
    INDEC ENDP
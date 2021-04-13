.MODEL SMALL 
.STACK 100H 
.CODE
MAIN PROC
    ;execute in DEBUG.Place in AX and B in BX
    CALL MULTIPLY
    ;DX will contain the product
    MOV AH,4CH
    INT 21H
    MAIN ENDP
MULTIPLY  PROC 
    ;multiplies two numbers A and B by shifting and addition
    ;input: AX=A,BX=B. Numbers in range 0-FFh 
    ;output:DX=product
    PUSH AX
    PUSH BX
    XOR DX,DX
    REPEAT:
    ;if B is odd
    TEST BX,1
    JZ END_IF
    ;then
    ADD DX,AX
    END_IF:  
    SHL AX,1
    SHR BX,1
    ;until
    JNZ REPEAT
    POP BX
    POP AX
    RET 
    MULTIPLY  ENDP
    END MAIN 
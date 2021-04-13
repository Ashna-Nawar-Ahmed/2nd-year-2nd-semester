READ_STR PROC NEAR
    ;Reads and stores a string
    ;input:DI offset of string
    ;output:DI offset of string
    ;BX number of characters read
    PUSH AX
    PUSH DI
    CLD
    XOR BX,BX
    MOV AH,1
    INT 21H
    WHILE1:
    CMP AL,0DH
    JE END_WHILE1
    ;if character is backspace
    CMP AL,8H
    JNE ELSE1
    ;then
    DEC DI
    DEC BX
    JMP READ
    ELSE1:
    STOSB
    INC BX
    READ:
    INT 21H
    JMP WHILE1
    END_WHILE1:
    POP DI
    POP AX
    RET
    READ_STR ENDP 
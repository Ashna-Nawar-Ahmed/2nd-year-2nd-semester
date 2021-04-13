.MODEL SMALL
.STACK 100H
.DATA
STRING DB 80 DUP (0)
VOWELS DB 'AEIOU'
CONSONANTS DB 'BCDFGHJKLMNPQRSTVWXYZ'
OUT1 DB 0DH,0AH,'vowels=$'
OUT2 DB ',consonants=$'
VOWELCT DW 0
CONSCT DW 0
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    MOV ES,AX
    LEA DI,STRING
    CALL READ_STR
    MOV SI,DI
    CLD 
    REPEAT:
    ;load a string character
    LODSB
    ;if it's a vowel
    LEA DI,VOWELS
    MOV CX,5
    REPNE SCASB
    JNE CK_CONST
    ;then increment vowel count
    INC VOWELCT
    JMP UNTIL
    ;else if it's a consonant
    CK_CONST:
    LEA DI,CONSONANTS 
    MOV CX,21
    REPNE SCASB
    JNE UNTIL
    ;then increment consonant count
    INC CONSCT
    UNTIL:
    DEC BX
    JNE REPEAT
    ;output no. of vowels
    MOV AH,9 
    LEA DX,OUT1
    INT 21H
    MOV AX,VOWELCT
    CALL OUTDEC
    ;output no. of consonants
    MOV AH,9
    LEA DX,OUT2
    INT 21H
    MOV AX,CONSCT
    CALL OUTDEC 
    ;dos exit
    MOV AH,4CH
    INT 21H
    MAIN ENDP
INCLUDE PGM11_1.ASM
INCLUDE PGM9_1.ASM
END MAIN 
                                   
DISP_STR PROC NEAR
;displays a string
;input:SI=offset of string and BX= numbers of characters to display
;output:none
PUSH AX
PUSH BX
PUSH CX
PUSH DX
PUSH SI
MOV CX,BX
JCXZ P_EXIT
CLD
MOV AH,2
TOP:
LODSB
MOV DL,AL
INT 21H
LOOP TOP
P_EXIT:
POP SI
POP DX
POP CX
POP BX
POP AX
RET
DISP_STR ENDP 
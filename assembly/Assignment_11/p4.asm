.MODEL SMALL
.CODE
FUNC PROC
    CMP BH,0
    JE L
    MOV AL,BL
    MOV AH,0
    DIV BH
    MOV BL,BH
    MOV BH,AH
    CALL FUNC
L:
    RET
FUNC ENDP
MAIN PROC
    MOV BL,54
    MOV BH,42
    MOV CL,0
    CALL FUNC
    ADD BL,48
    MOV DL,BL
    MOV AH,2
    INT 21H
    MOV AH,76
    INT 21H
MAIN ENDP
END MAIN
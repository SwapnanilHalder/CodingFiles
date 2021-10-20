.MODEL SMALL
.CODE
    MOV AH,1
    INT 33
    MOV DL,AL
    SUB AL,48
    MOV BL,AL
    REPT 10
    CMP BL,0
    JE L
    SUB BL,1
    ADD DL,1
    ENDM
    L:
        MOV AH,2
    INT 33
    MOV AH,76
    INT 33
END

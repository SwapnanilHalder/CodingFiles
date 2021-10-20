.MODEL SMALL
.CODE
    MOV AH,1
    INT 33
    SUB AL,48
    MOV BL,AL
    INT 33
    SUB AL,48
    MOV DL,0
    REPT 10
    CMP BL,0
    JE L1
    ADD DL,AL
    SUB BL,1
    ENDM
    L1:
        MOV AH,2
    INT 33
    MOV AH,76
    INT 33
END

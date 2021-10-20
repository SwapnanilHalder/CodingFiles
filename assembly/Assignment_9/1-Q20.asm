.MODEL SMALL
.CODE
    MOV AH,1
    INT 33
    REPT 20
    CMP AL,7
    JL L
    SUB AL,7
    ENDM
    L:
        MOV AH,2
    MOV DL,48
    ADD DL,AL
    INT 33
    MOV AH,76
    INT 33
END

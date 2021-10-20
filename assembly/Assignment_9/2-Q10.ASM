.MODEL SMALL
.CODE
    MOV AH,1
    INT 33
    SUB AL,69
    REPT 7
    T=0
    REPT 3
    CMP AL,T
    JE L
    T=T+1
    ENDM
    SUB AL,3
    ENDM
    L:MOV AH,2
    MOV DL,48
    ADD DL,AL
    INT 33
    MOV AH,76
    INT 33
END

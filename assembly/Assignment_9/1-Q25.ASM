.MODEL SMALL
.CODE
    MOV AH,1
    MOV DL,0
    T=1
    REPT 10
    INT 33
    SUB AL,48
    REPT T
    ADD DL,AL
    ENDM
    T=T+1
    ENDM
    MOV AH,2
    INT 33
    MOV AH,76
    INT 33
END

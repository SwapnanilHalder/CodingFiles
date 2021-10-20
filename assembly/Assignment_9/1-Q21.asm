.MODEL SMALL
.CODE
    MOV AH,1
    INT 33
    MOV BL,0
    REPT 20
    CMP AL,10
    JL L
    SUB AL,10
    ADD BL,1
    ENDM
    L:
        MOV AH,2
    MOV DL,48
    ADD DL,BL
    INT 33
    MOV AH,76
    INT 33
END

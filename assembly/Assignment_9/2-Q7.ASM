.MODEL SMALL
.CODE
    MOV AH,1
    INT 33
    SUB AL,48
    MOV BL,AL
    MOV AH,2
    MOV DL,'A'
    REPT 10
    CMP BL,0
    JE L
    SUB BL,1
    INT 33
    ENDM
    L:
        MOV AH,76
    INT 33
END

.MODEL SMALL
.CODE
    MOV AH,1
    MOV DL,'A'
    REPT 10
    INT 33
    CMP AL,'A'
    JE L1
    MOV DL,AL
    ENDM
    L1:
        MOV AH,2
    INT 33
    MOV AH,76
    INT 33
END

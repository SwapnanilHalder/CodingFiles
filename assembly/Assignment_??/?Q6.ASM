.MODEL SMALL
.CODE
    MOV AH,1
    INT 33
    MOV DL,AL
    INT 33
    DB 00111010B
    DB 11010000B
    JG L
    XCHG DL,AL
    L:MOV AH,2
    INT 33
    MOV AH,76
    INT 33
END
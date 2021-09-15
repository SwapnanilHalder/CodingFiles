.MODEL SMALL
.CODE
    MOV BX, 0
    MOV CX, 0
    SUMLOOP:
        MOV AH, 1
        INT 33
        MOV AH, 0
        ADD CX, AX
        INC BX
        CMP BX, 10
        JL SUMLOOP
    
    MOV BX, 0
    MOV AH, 0

    AVGLOOP:
        SUB CX, 10
        INC BX
        CMP CX, 10
        JGE AVGLOOP
    
    MOV DX, BX
    MOV AH, 2
    INT 33
    MOV AH, 76
    INT 33
END

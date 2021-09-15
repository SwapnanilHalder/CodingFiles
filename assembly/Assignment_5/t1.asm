.MODEL SMALL
.CODE
    MOV AH, 1
    INT 33
    MOV BX, 2000
    MOV DX, 0
    MOV AH, 0

    DIVLOOP:
        SUB BX, AX
        INC DX
        CMP BX, AX
        JGE DIVLOOP
    
    MOV AH, 2
    INT 33
    MOV AH, 76
    INT 33
END
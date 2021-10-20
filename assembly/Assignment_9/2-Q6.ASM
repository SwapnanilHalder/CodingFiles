.MODEL SMALL
.CODE
    MOV AH,1
    INT 33
    SUB AL,'0'
    MOV DL,AL
    INC DL
    MUL DL
    SHR AX,1
    ADD AX,'2'
    MOV DL,AL
    MOV AH,2
    INT 33
    MOV AH,76
    INT 33
END
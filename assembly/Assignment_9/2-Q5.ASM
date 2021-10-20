.MODEL SMALL
.CODE
    MOV AH,1
    INT 33
    SUB AL,'0'
    MOV DL,AL
    INT 33
    SUB AL,'0'
    MUL DL
    MOV DL,AL
    MOV AH,2
    INT 33
    MOV AH,76
    INT 33
END
.MODEL SMALL
.CODE
    MOV AH,1
    INT 33
    SUB AL,80
    MOV BL,AL
    MOV AX,-1000
    IDIV BL
    MOV DL,AL
    MOV BL,AH
    ADD DL,75
    ADD BL,75
    MOV AH,2
    INT 33
    MOV DL,BL
    INT 33
    MOV AH,76
    INT 33
END
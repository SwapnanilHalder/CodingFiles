.MODEL SMALL
.CODE
    MOV AH,1
    INT 33
    SUB AL,80
    MOV BL,-13
    IMUL BL
    ADD AX,75
    MOV AH,0
    MOV DL,AL
    MOV AH,2
    INT 33
    MOV AH,76
    INT 33
END
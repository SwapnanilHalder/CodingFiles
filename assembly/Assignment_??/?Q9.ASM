.MODEL SMALL
.CODE
    MOV AH,2
    MOV DL,65
    MOV CX,26
    L:INT 33
    INC DL
    LOOP L
    MOV AH,76
    INT 33
END
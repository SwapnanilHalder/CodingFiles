.MODEL SMALL
.DATA
    A DB 'wadctzhfred'
.CODE
    MOV AX,@DATA
    MOV DS,AX
    LEA SI,A+5
    STD
    LODSB
    MOV AH,2
    MOV CX,5
    L: LODSB
    MOV DL,AL
    INT 21H
    LOOP L
    MOV AH,76
    INT 21H
END
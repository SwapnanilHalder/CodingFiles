.MODEL SMALL
.CODE
    MOV AH,1
    INT 33
    MOV BL,AL
    INT 33
    MOV BH,AL
    MOV AH, 2
    MOV DX, 0
    MOV CX, 0
    MOV DL, BL
    L1:
        ADD CX, DX
        INC DL
        CMP DL, BH
        JLE L1
    
    MOV DL,CH
    INT 33
    MOV DL,CL
    INT 33
    MOV AH,76
    INT 33
END
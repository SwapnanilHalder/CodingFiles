.MODEL SMALL
.CODE
    MOV AH,1
    INT 33
    MOV CH,AL
    INT 33
    MOV CL,AL
    MOV AH,0

    L1:
        SUB CX,150
        CMP CX,150
        JGE L1

    MOV AH,2
    MOV DX,CX
    INT 33
    MOV AH,76
    INT 33
END
t
cl - 150
5 0
.MODEL SMALL
.CODE
    MOV AH,1
    INT 33
    MOV BL,AL
    INT 33
    MOV BH,AL
    MOV DX,0
    MOV CX,0
    MOV DL,BL

    MULTLOOP:
        ADD CX,DX
        DEC BH
        CMP BH,0
        JG MULTLOOP

    MOV AH,2
    MOV DL,CH
    INT 33
    MOV DL,CL
    INT 33
    MOV AH,76
    INT 33
END
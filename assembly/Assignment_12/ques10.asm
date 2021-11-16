.MODEL SMALL
.CODE
    MOV AH,1
    INT 33
    MOV DL,AL
    MOV BH,200
    MOV BL,100
    MOV CL,01H
    AND CL,DL
    JZ LOOPY
    ADD BH,BL
    ADC DL,0
    LOOPY:
    MOV AH,2
    INT 33
    MOV AH,76
    INT 33
END
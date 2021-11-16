.MODEL SMALL
.CODE
    MOV DL,'B'
    MOV AH,1
    INT 33
    ADD AL,150
    MOV CL,0
    ADC CL,0
    SUB DL,CL
    MOV AH,2
    INT 33
    MOV AH,76
    INT 33
END
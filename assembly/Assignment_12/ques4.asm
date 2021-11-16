.MODEL SMALL
.CODE
    MOV DL,'A'
    MOV AH,1
    INT 33
    ADD AL,150
    ADC DL,0
    MOV AH,2
    INT 33
    MOV AH,76
    INT 33
END
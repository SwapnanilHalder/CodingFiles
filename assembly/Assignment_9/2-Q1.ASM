.MODEL SMALL
.CODE
    MOV AH,1
    MOV BL,0
    REPT 9
    INT 33
    ADD AL,155
    ADC BL,0
    ENDM
    MOV DL,9
    SUB DL,BL
    ADD DL,48
    MOV AH,2
    INT 33
    MOV AH,76
    INT 33
 END

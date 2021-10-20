.MODEL SMALL
.CODE
    MOV AH,1
    INT 33
    REPT 40
    MOV AH,0
    SUB AX,7
    AND AH,1
    REPT 7
    ADD AL,AH
    ENDM     
    ENDM
    MOV AH,2
    MOV DL,AL
    ADD DL,'0'
    INT 33
    MOV AH,76
    INT 33
END
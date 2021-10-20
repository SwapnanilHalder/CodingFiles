.MODEL SMALL
.CODE
    MOV DL,48
    REPT 9
    MOV AH,1
    INT 33
    ADD AL,28
    CBW            
    ADD DL,AH     
    ENDM
    ADD DL,9
    MOV AH,2
    INT 33
    MOV AH,76
    INT 33
END

.MODEL SMALL
.STACK 100H
.DATA
.CODE
    MAIN PROC
        MOV AH,1
        INT 33
        DB 11111110B
        DB 11000000B
        MOV DL,AL
        MOV AH,2
        INT 33
        MOV AH,76
        INT 33
    MAIN ENDP
END MAIN
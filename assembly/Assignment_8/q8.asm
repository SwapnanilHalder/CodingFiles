.MODEL SMALL
.STACK 100H
.DATA
.CODE
    MAIN PROC
        MOV AH,1
        INT 33
        MOV DL,AL
        INT 33
        CMP DL,AL
        DB 01111111B
        DB 2D
        XCHG DL,AL
        MOV AH,2
        INT 33
        MOV AH,76
        INT 33
    MAIN ENDP
END MAIN
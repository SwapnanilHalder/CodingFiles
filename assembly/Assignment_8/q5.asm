.MODEL SMALL
.STACK 100H
.DATA
.CODE
    MAIN PROC
        MOV AH,1
        INT 33
        MOV DL,65
        DB 00111100B
        DB 100D
        JG L
        INC DL
        L:  MOV AH,2
        INT 33
        MOV AH,76
        INT 33
    MAIN ENDP
END MAIN
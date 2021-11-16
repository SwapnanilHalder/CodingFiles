.MODEL SMALL
.STACK 100H
.CODE
    MOV DL,'B'
    MOV AH,1
    INT 33
    MOV BH,AL
    INT 33
    MOV BL,AL
    ADD BH,150
    JNC LOOPY
    ADD BL,150
    PUSHF
    POP AX
    AND AL,01H
    SUB DL,AL
    LOOPY:
    MOV AH,2
    INT 33
    MOV AH,76
    INT 33
END
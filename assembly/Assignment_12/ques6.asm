.MODEL SMALL
.STACK 100H
.CODE
    MOV DL,'B'
    MOV CL,3
    MOV AH,1
    INT 33
    ADD AL,50
    PUSHF
    POP AX
    AND AH,0001000B
    SHR AH,CL
    SUB DL,AH
    MOV AH,2
    INT 33
    MOV AH,76
    INT 33
END
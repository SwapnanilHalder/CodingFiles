.MODEL SMALL
.STACK 100H
.CODE
    MOV AH,1
    INT 33
    MOV BH,AL
    INT 33
    MOV BL,AL
    MOV AH,2
    ADD BH,BL
    PUSHF
    POP AX
    AND AL,10H
    CMP AL,10H
    JE LOOPY
    MOV AH,2
    MOV DL,66
    JMP L2
    LOOPY:
    MOV AH,2
    MOV DL,65
    L2:
    INT 33
    MOV AH,76
    INT 33
END
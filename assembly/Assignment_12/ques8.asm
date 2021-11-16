.MODEL SMALL
.CODE
    MOV CL,7
    MOV AH,1
    INT 33
    MOV BH,AL
    ADD BH,70
    INT 33
    MOV BL,AL
    ADD BL,10
    CMP BL,BH
    PUSHF
    POP AX
    SHR AX,CL
    AND AX,0011H
    CMP AL,17
    JE LOOPY
    CMP AL,0
    JE LOOPY
    MOV DL,'B'
    JMP L2
    LOOPY:
    MOV DL,'A'
    L2:
    MOV AH,2
    INT 33
    MOV AH,76
    INT 33
END
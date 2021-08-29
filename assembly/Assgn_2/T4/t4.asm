.model small
.code

    MOV AH, 1
    INT 21H
    MOV BL, AL
    SUB BL, '0'
    INT 21H
    MOV CL, AL
    SUB CL, '0'
    MOV DL, 0
    ADD DL, BL
    ADD DL, CL
    CMP DL, 10
    JGE L2
    JMP L1

    L1:
        ADD DL, '0'
        MOV AH, 2
        INT 21H
        JMP L3
    
    L2:
        MOV CL, DL
        MOV DL, '1'
        MOV AH, 2
        INT 21H
        MOV DL, CL
        SUB DL, 10
        ADD DL, '0'
        INT 21H
        JMP L3

    L3:
        MOV AH, 76
        INT 21H
END

.MODEL SMALL
.STACK 100h
.CODE

    MOV  AH, 1
    INT  33
    MOV  CH, AL
    INT  33
    MOV  CL, AL
    INC  AH
    L1:
        CMP  CX, 0
        JE   ENDFLAG
        XOR  BX, BX
        L2:
            CMP  CX, 10
            JB   L3
            INC  BX
            SUB  CX, 10
            JMP  L2
        L3:
            ADD  CL, 48
            MOV  DL, CL
            INT  33
            MOV  CX, BX
            JMP  L1

    ENDFLAG:
        MOV  AH, 76
        INT  33
END
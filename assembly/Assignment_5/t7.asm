.MODEL SMALL
.STACK 100h
.CODE

    XOR  CX,CX
    MOV  DX,5
    L1:
        CMP  DL,0
        JE   L2

        MOV  AH,1
        INT  33
        MOV  BX,CX
        MOV  AH,9
        MULTLOOP:
            ADD  CX,BX
            DEC  AH
            JNZ  MULTLOOP

        AND  AL,0Fh
        ADD  CL,AL
        ADC  CH,0
        DEC  DL
        JMP  L1
    L2:
        MOV  AH,2
        MOV  DL,CH
        INT  33
        MOV  DL,CL
        INT  33
        MOV  AH,76
        INT  33
END
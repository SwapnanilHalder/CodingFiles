.MODEL SMALL
.CODE
    MOV AH,1
    INT 21H
    MOV CH,AL
    INT 21H
    MOV CL,AL
    MOV BX,CX
    MOV DX,1
    L2:
        ADD DX,1
        MOV CX,BX
        L1:
            SUB CX,DX
            CMP CX,DX
            JGE L1
        CMP CX,0
        JNZ L2
        
    MOV AH,2
    INT 21H
    MOV AH,76
    INT 21H
END
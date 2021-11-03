.MODEL SMALL
.CODE
FUNC PROC
    MOV DX,1
    CMP AH,AL
    JZ LOOPY
    CMP AL,0
    JZ LOOPY
    DEC AH
    CALL FUNC
    DEC AL
    CALL FUNC
    INC AH
    INC AL
    MOV DX,0
LOOPY: 
    ADD CX,DX
    RET
FUNC ENDP
MAIN PROC
    MOV AH,1
    INT 33
    MOV BH,AL
    INT 33
    SUB AL,48
    SUB BH,48
    MOV AH,BH
    XOR CX,CX
    CALL FUNC
    MOV AH,2
    MOV DL,32
    INT 33
    MOV DL,CL
    INT 33
    MOV AH,76
    INT 33
MAIN ENDP
END MAIN
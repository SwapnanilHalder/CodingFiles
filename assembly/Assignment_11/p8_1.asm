.MODEL SMALL
.CODE
FIRSTDIG PROC
    CMP AX,10
    JB LOOPY
    MOV DX,0
    MOV BX,10
    DIV BX
    CALL FIRSTDIG
LOOPY: 
    RET
FIRSTDIG ENDP
MAIN PROC
    MOV AX,23415
    CALL FIRSTDIG
    MOV DX,AX
    ADD DL,48
    MOV AH,2
    INT 33
    MOV AH,76
    INT 33
MAIN ENDP
END MAIN
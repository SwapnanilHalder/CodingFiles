.MODEL SMALL
.DATA
    ARR DB 100 DUP(?)
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    LEA SI,ARR
    MOV AH,1
    MOV CX,9
    MOV BX,0
    L1:
        INT 33
        MOV [SI],AL
        XOR BX,1
        ADD SI,BX
        LOOP L1
    INT 33
    MOV AH,9
    MOV CL, 36
    MOV [SI], CL
    LEA DX,ARR
    INT 33
    MOV AH,76
    INT 33
MAIN ENDP
    END MAIN
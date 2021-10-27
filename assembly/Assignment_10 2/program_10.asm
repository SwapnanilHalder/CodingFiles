.MODEL SMALL
.DATA
    STR DB 100 DUP('$')
    B DB 100 DUP('$')
.CODE
    MOV AX,@DATA
    MOV DS,AX
    MOV ES,AX
    LEA DI,STR
    CLD
    MOV BX,1
    MOV AH,1
    FLAG1: 
        INT 33
    CMP AL,'$'
    JE FLAG2
    STOSB
    JMP FLAG1
    FLAG2: 
        MOV AH,2
    MOV DL,10
    INT 33
    TEST BX,1
    JE FLAG3
    DEC BX
    LEA DI,B
    MOV AH,1
    JMP FLAG1
    FLAG3: 
        MOV CX,255
    LEA SI,STR
    LEA DI,B
    REPNE CMPSB
    DEC SI
    DEC DI
    NEG CX
    DEC CX
    STD
    REP MOVSB
    MOV AH,9
    LEA DX,B
    INT 33
    MOV AH,76
    INT 33
END
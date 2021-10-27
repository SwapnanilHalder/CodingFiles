.MODEL SMALL
.DATA
    STR DB 100 DUP('$')
.CODE
    MOV AX,@DATA
    MOV DS,AX
    MOV ES,AX
    LEA DI,STR
    CLD
    MOV AH,1
    FLAG1: 
        INT 33
    CMP AL,'$'
    JE FLAG2
    STOSB
    JMP FLAG1
    FLAG2: 
        LEA SI,STR
    CLD
    MOV CX,7
    REP LODSB
    AND AL,15
    INC AL
    DEC SI
    MOV CL,AL
    MOV CH,0
    STD
    REP LODSB
    MOV AH,2
    MOV DL,AL
    INT 33
    MOV AH,76
    INT 33
END
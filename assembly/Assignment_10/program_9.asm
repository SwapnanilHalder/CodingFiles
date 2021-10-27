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
    MOV SI,DI
    LEA DI,B
    MOV AH,1
    JMP FLAG1
    FLAG3: 
        XCHG SI,DI
    DEC DI
    LEA SI,B+3
    STD
    MOV CX,4
    REP MOVSB
    MOV AH,9
    LEA DX,STR
    INT 33
    MOV AH,76
    INT 33 
END
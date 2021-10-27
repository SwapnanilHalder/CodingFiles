.MODEL SMALL
.DATA
    STR DB 100 DUP('$')
.CODE
    MOV AX,@DATA
    MOV DS,AX
    MOV ES,AX
    XOR CX,CX
    LEA DI,STR
    CLD
    MOV AH,1
    FLAG1: 
        INT 33
    CMP AL,'$'
    JE FLAG2
    STOSB
    INC CX
    JMP FLAG1
    FLAG2: 
        MOV BX,CX
    MOV AL,'T'
    LEA DI,STR
    REPE SCASB
    SUB BX,CX
    DEC BX
    MOV DL,BL
    ADD DL,48
    MOV AH,2
    INT 33
    MOV AH,76
    INT 33
END
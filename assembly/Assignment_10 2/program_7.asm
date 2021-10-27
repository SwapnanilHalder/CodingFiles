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
    INC CX
    JMP FLAG1
    FLAG2: 
        STD
    DEC DI
    MOV SI,DI
    FLAG3: 
        LODSB
    CMP AL,'9'
    JNE FLAG4
    MOV AL,'0'
    STOSB
    JMP FLAG3
    FLAG4: 
        INC AL
    STOSB
    LEA DX,STR
    MOV AH,9
    INT 33
    MOV AH,76
    INT 33
END
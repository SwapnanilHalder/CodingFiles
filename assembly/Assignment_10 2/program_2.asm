.MODEL SMALL
.DATA
    STR DB 'PQADRTFTYG$'
.CODE
    MOV AX,@DATA
    MOV DS,AX
    MOV ES,AX
    MOV AH,1
    INT 33
    AND AL,15
    MOV BL,AL
    MOV BH,0
    LEA DI,STR
    ADD DI,BX
    INT 33
    AND AL,15
    SUB AL,BL
    MOV CL,AL
    INC CL
    MOV CH,0
    MOV AL,'X'
    CLD
    REP STOSB
    MOV AH,9
    LEA DX,STR
    INT 33
    MOV AH,76
    INT 33
END
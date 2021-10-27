.MODEL SMALL
.DATA
    STR DB 'PQADRTFTYG$'
.CODE
    MOV AX,@DATA
    MOV ES,AX
    MOV DS,AX
    MOV AH,1
    INT 33
    AND AL,15
    MOV CL,AL
    MOV CH,0
    MOV AL,'X'
    CLD
    LEA DI,STR
    REP STOSB
    LEA DX,STR
    MOV AH,9
    INT 33
    MOV AH,76
    INT 33
END
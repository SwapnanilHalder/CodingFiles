.MODEL SMALL
.STACK 100H
.CODE
MAIN PROC
    MOV BH,5
    MOV DL,65
    CALL PRINT
    MOV AH,76
    INT 21H
MAIN ENDP
PRINT PROC
    CMP BH,0
    JBE EXIT
    MOV AH,2
    INT 21H
    INC DL
    DEC BH
    CALL PRINT
EXIT:
    RET    
PRINT ENDP
END MAIN
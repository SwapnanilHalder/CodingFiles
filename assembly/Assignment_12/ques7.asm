.MODEL SMALL
.CODE
    MOV DL,'A'
    MOV AH,1
    INT 33
    ADD AL,28
    ADD AL,50
    JO LOOPY
    MOV DL,'B'
    LOOPY:
    MOV AH,2
    INT 33
    MOV AH,76
    INT 33
END
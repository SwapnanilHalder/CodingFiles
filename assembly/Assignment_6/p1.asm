.MODEL SMALL
.STACK 100H
.DATA
	ARR DB 100 DUP (?)
.CODE
	MOV AX,@DATA
	MOV DS,AX
	MOV SI,-1
	MOV AH,1
	INPUT:
		INT 21H
		CMP AL,13
		JE STOP
		INC SI
		MOV ARR[SI],AL
		JMP INPUT
	STOP:
		MOV CX,SI
		MOV SI,0
		MOV AH,2
	OUTPUT:
		CMP SI,CX
		JG PROG_END
		MOV DL,ARR[SI]
		INT 21H
		ADD SI,2
		JMP OUTPUT
	PROG_END:
		MOV AH,76
		INT 21H
END

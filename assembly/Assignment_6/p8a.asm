.MODEL SMALL
.DATA
ARR DB 100 DUP('?')
.CODE
	XOR CX,CX
	MOV AX,@DATA
	MOV DS,AX
	LEA SI,ARR
	MOV CX,10
	MOV AH,1
	READ:
		INT 33
		MOV [SI],AL
		INC SI
		LOOP READ
	SUB SI,5
	MOV CL,36
	MOV [SI],CL
	MOV AH,9
	INT 33
	MOV AH,76
	INT 33
END
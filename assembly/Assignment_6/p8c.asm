;Q.8 C

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
	;ADD '$' AT POSITION 8
	SUB SI,2
	MOV CL,36
	MOV [SI],CL
	LEA DX,ARR
	ADD DX,3
	MOV AH,9
	INT 21H
	MOV AH,76
	INT 33
END

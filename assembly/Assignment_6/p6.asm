.MODEL SMALL
.DATA
	ARR DB 100 DUP('?')
.CODE
	XOR CX,CX
	MOV AX,@DATA
	MOV DS,AX
	LEA SI,ARR
	MOV AH,1
	INT 33
	MOV CL,AL
	SUB CL,'0'
	MOV BX,CX
	READ:
		INT 33
		MOV [SI],AL
		INC SI
		LOOP READ
	MOV AH,2
	MOV CX,BX
	OUTPUT:
		DEC SI
		MOV DL,[SI]
		INT 33
		LOOP OUTPUT
	MOV AH,76
	INT 33
END

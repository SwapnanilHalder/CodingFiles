.model small
.code
	mov ah,1
	int 33
	mov bh,al
	int 33
	mov ah,2
	mov bl,al
	mov al,bh
	l1:
		sub al,2
		cmp al,2
	jge l1
	cmp al,1 ; if true, atleast one is odd
	je l3
	l2:
		sub bl,2
		cmp bl,2
	jge l2
	cmp bl,1 ; both even
	je l3
	jmp l4
	l3:
		mov dl,'B'
		jmp endflag
	l4:
		mov dl,'A'
        jmp endflag
	endflag:
		int 33
		mov ah,76
		int 33
END
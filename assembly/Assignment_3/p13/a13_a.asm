.model small
.code
	mov ah,2
	mov dl,'F'
	l1:
		int 33
		sub dl, 1
		cmp dl,'A'
	jge l1
	mov ah,76
	int 33
END

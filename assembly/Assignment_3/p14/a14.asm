.model small
.code
	mov ah,1
	int 33
    mov ah,2
l1:
    sub al,2
    cmp al,2
	jge l1 ; loop to reduce the number between 0, 1
	cmp al,0
	je l2
	jmp l3
l2:
    mov dl,'A'
    jmp l4
l3:
    mov dl,'B'
    jmp l4
l4:
    int 33
    mov ah,76
    int 33
END
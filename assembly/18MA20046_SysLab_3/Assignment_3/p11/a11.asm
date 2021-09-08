.model small
.code
    mov ah, 1 ; input mode
    int 33
    mov ah, 2  ; print mode
    cmp al, 70
    JA L1
    JMP L2
    L1 :
		cmp al,97
		ja l2
		mov dl,'A'
		jmp l3
	L2:
		mov dl,'B'
	L3:
		int 33
		mov ah,76
		int 33
    END

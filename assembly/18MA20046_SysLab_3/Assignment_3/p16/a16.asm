.model small
.code
	mov ah,1
	int 33
    mov ah,2
    mov dl,'A'
	cmp al,40
	jl l1
	cmp al,50
	jl l2
	cmp al,60
	jl l1
	cmp al,70
	jl l2
	cmp al,80
	jl l1
	cmp al,90
	jl l2
	cmp al,100
	jl l1
	cmp al,110
	jl l2
	cmp al,120
	jl l1
	cmp al,130
	jl l2
	jmp l1
	l1:
		add dl, 1
	l2:
		int 33
		mov ah,76
		int 33
END
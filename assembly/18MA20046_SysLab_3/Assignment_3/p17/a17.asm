.model small
.code
	mov ah,1
	int 33
	mov ah,2
	cmp al,30
	jl l3
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
	jmp l3
	l1:
		oddloop:
			sub al,2
			cmp al,2
		jge oddloop
		cmp al,0
		je l3
		mov dl,'A'
		jmp l4
	l2:
		evenloop:
			sub al,2
			cmp al,2
		jge evenloop
		cmp al,1
		je l3
		mov dl,'A'
		jmp l4
	l3:
		mov dl,'B'
	l4:
		int 33
		mov ah,76
		int 33
END

.model small
.code
mov ah, 1
int 33

mov cx, 0
loop:   cmp ax, bx
        jl endloop
        sub ax, bx
        inc cx
        jmp loop

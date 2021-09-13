.model small
.code

mov ah,1
int 33
mov ah,2
cmp al,70
jg L1
jmp L2
L1:
    cmp al,226
    jg L2
    mov dl,'A'
    jmp L3
L2:
    mov dl,'B'
L3:   
    int 33
    mov ah,76
    int 33
END

.model small
.code
    mov ah,1
    int 33
    mov ah,0
    mov bl,5
    sub ax,80
    idiv bl
    mov dl,al
    add dl,75
    mov ah,2
    int 33
    mov ah,76
    int 33
end
.model small
.data
    a db 66, 69, 80, 72

.code
    MOV ax, @data
    mov ds, ax
    lea dx, a
    mov ah, 9
    add dx, 1
    mov si, dx
    mov [SI+1], byte ptr 36
    int 33
    mov ah, 76
    int 33
end

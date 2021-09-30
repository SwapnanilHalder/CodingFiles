.model small
.code
    mov ah, 1
    int 33
    mov ah, 0
    mov cx, ax
    mov ah, 1
    int 33
    mov ah, 0
    mul cx
    mov cx, ax
    mov ah, 1
    int 33
    mov ah, 0
    mul cx
    mov cx, ax
    mov dl, ch
    mov ah, 2
    int 33
    mov ah, 76
    int 33
END
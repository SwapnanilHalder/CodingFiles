.model small
.code
    mov ah, 2
    mov cx, -256
    mov dx, 255
    sub dx, cx
    int 33
    mov ah, 76
    int 33
END
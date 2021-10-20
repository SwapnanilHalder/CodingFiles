.model small
.code
    mov ah, 1
    int 33
    mov dl, 70
    add ax, 177
    add dl, ah
    mov ah, 2
    int 33
    mov ah, 76
    int 33
end
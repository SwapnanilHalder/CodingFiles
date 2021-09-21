.model small
.data
    a db 66, 69, 80, 72, 65, 68, 36

.code
    MOV ax, @data
    mov ds, ax
    lea si, a

    mov [SI+2], byte ptr 110
    lea dx, a
    mov ah, 9
    int 33
    mov ah, 76
    int 33
end

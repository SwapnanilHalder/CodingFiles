.model small
.stack 100h
.data
.code
main PROC
    mov ah, 1
    int 33
    sub al, '0'
    mov cl, al
    xor ch, ch
    loopy:
        mov ah, 1
        int 33
        mov ah, 2
        mov dl, al
        inc dl
        int 33
        loop loopy
    mov ah, 76
    int 33
main ENDP
    end main
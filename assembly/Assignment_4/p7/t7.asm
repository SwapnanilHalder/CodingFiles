.model small
.stack 100h
.data
.code
main PROC
    mov ah, 1
    int 33
    mov dl, al
    int 33
    mov bh, al
    sub bh, dl
    mov cl, bh
    inc cl
    xor ch, ch
    mov ah, 2
    loopy:
        int 33
        inc dl
        loop loopy
    mov ah, 76
    int 33
main ENDP
    end main
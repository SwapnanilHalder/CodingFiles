.model small
.code

    mov ah, 2
    mov dl, 'A'
    mov bl, 1
    loopy:
        mov cl, bl
        xor ch, ch
        l1:
            int 33
            dec cl
            cmp cl, 0
            jg l1
        inc dl
        inc bl
        cmp bl, 4
        jle loopy
    mov ah, 76
    int 33
    end
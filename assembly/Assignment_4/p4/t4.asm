.model small
.code
;description :
main PROC
    mov ah, 1
    int 33
    sub al, '0'
    mov dl, al
    mov cl, 9
    xor ch, ch
    loopy:
        add dl, al
        loop loopy
    int 33
    sub al, '0'
    add dl, al
    mov ah, 2
    int 33
    mov ah, 76
    int 33
main ENDP
    end main
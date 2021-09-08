.model small
.code
;description
main PROC
    mov ah, 1
    int 33
    mov ah, 2
    and al, 0Fh
    mov cl, 9 ; add 9 times more
    mov ch, 0
    mov dl, al
    loopy:
        add dl, al
        loop loopy
    int 33
    mov ah, 76
    int 33
main ENDP
    end main
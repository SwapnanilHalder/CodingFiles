.model small
.code
;description
main PROC
    mov ah, 1
    int 21h
    mov ah, 2
    mov dl, al
    mov cl, 10
    mov ch, 0
    l1:
        int 21h
        xor dl, dl
        ; mov dl, cl
        ; add dl, '0'
        ; int 21h
        mov dl, al
        loop l1
    mov ah, 76
    int 21h
main ENDP
    end main
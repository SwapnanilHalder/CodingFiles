.model small
.stack 100h
.data
.code
main proc
    mov ah, 1
    int 33
    and al, 0Fh
    mov cl, al
    mov ch, 0
    mov ah, 2
    mov dl, 'K'
    cmp al, 0
    je l2
    l1:
        int 33
        loop l1
    l2:
        mov ah, 76
        int 33
main endp
    end main
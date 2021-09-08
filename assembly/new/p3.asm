.model small
.stack 100h
.data
.code
main proc
    mov ah, 1
    int 33
    and al, 0Fh
    mov cl, 9
    mov ch, 0
    mov dl, al
    l1:
        add dl, al
        loop l1
    mov ah, 2
    int 33
    mov ah, 76
    int 33
main endp
    end main
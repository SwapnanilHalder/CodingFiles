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
    l1:
        mov ah, 1
        int 33
        mov dl, al
        add dl, 1
        mov ah, 2
        int 33
        loop l1
    mov ah, 76
    int 33
main endp
    end main
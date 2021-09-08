.model small
.stack 100h
.data
.code
main proc
    mov ah, 1
    int 33
    mov bl, al
    int 33
    mov bh, al
    mov dl, bl
    sub bh, bl
    mov cl, bh
    add cl, 1
    mov ch, 0
    mov ah, 2
    l1:
        int 33
        add dl, 1
        loop l1
    mov ah, 76
    int 33
main endp
    end main
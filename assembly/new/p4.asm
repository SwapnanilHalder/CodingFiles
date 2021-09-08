.model small
.stack 100h
.data
.code
main proc
    mov ah, 1
    int 33
    and al, 0Fh
    mov bl, al
    mov cl, 9
    mov ch, 0
    l1:
        add bl, al
        loop l1
    int 33  
    and al, 0Fh  
    mov bh, al
    add bh, bl
    mov dl, bh
    mov ah, 2
    int 33
    mov ah, 76
    int 33
main endp
    end main
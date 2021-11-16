.model small
.stack 100h
.code
main proc
    mov dl,66
    mov ah,1
    int 33
    mov bh,al
    int 33
    mov bl,al
    add bh,150
    jnc l
    add bl,150
    pushf
    pop ax
    and al,01h
    sub dl,al
    l:
    mov ah,2
    int 33
    mov ah,76
    int 33
main endp
    end main
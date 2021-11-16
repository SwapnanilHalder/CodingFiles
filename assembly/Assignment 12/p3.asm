.model small
.stack 100h
.code
main proc
    mov ah,1
    mov dl,66
    int 33
    mov bh,al
    add bh,150
    pushf
    pop ax
    and al,01h
    jp l
    sub dl,1
    l:
    mov ah,2
    int 33
    mov ah,76
    int 33
main endp
    end main
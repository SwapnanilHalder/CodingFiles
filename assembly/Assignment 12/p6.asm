.model small
.stack 100h
.code
main proc
    mov dl,66
    mov cl,3
    mov ah,1
    int 33
    add al,50
    pushf
    pop ax
    and ah,0001000b
    shr ah,cl
    sub dl,ah
    mov ah,2
    int 33
    mov ah,76
    int 33
main endp
    end main
.model small
.code
main proc
    mov dl,65
    mov ah,1
    int 33
    add al,27
    add al,51
    jo l
    mov dl,66
    l:
    mov ah,2
    int 33
    mov ah,76
    int 33
main endp
    end main
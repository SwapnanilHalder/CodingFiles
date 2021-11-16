.model small
.code
main proc
    mov cl,7
    mov ah,1
    int 33
    mov bh,al
    add bh,70
    int 33
    mov bl,al
    add bl,10
    cmp bl,bh
    pushf
    pop ax
    shr ax,cl
    and ax,0011h
    cmp al,17
    je l1
    cmp al,0
    je l1
    mov dl,66
    jmp l2
    l1:
    mov dl,65
    l2:
    mov ah,2
    int 33
    mov ah,76
    int 33
main endp
    end main
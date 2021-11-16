.model small
.stack 100h
.code
main proc
    mov ah,1
    int 33
    mov bh,al
    int 33
    mov bl,al
    mov ah,2
    add bh,bl
    pushf
    pop ax
    and al,10h
    cmp al,10h
    je l1
    mov ah,2
    mov dl,66
    jmp l2
    l1:
    mov ah,2
    mov dl,65
    l2:
    int 33
    mov ah,76
    int 33
main endp
    end main
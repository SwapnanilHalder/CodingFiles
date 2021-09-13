.model small
.code
main proc
    x:int 21h
    jmp z
    y:mov bh,2
    z:mov ah,bh
    mov dl,'C'
    mov bh,76
    jmp x
main endp
    end y

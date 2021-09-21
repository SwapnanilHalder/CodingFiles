.model small
.code
    mov ah, 1
    mov dl, '0'
    xor cl, cl
    l1: cmp cl, 4
        je endloop
        inc dl
        int 33
        cmp al, 72
        jge l2
        jmp l1
        l2: cmp al, 84
            jle l3
            jmp l1
            l3: inc cl
                jmp l1
    endloop: mov ah, 2
    int 33
    mov ah, 76
    int 33
end

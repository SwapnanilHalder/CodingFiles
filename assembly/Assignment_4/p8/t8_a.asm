.model small
.stack 100h
.data
.code
main proc
    mov ah, 1
    mov cl, 9
    xor ch, ch
    xor dl, dl
    l1:
        int 33
        cmp al, 'a'
        loopnz skip
        inc dl
        skip:
            inc cx
            loop l1
    add dl, '0'
    mov ah, 2
    int 33
    mov ah, 76
    int 33
main endp
    end main
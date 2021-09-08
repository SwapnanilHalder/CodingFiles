.model small
.stack 100h
.data
.code
main proc
    mov cl, 10
    mov ch, 0
    mov ah, 1
    l1:
        int 33
        cmp al, 'a'
        loopz endloop
        inc cx
        loop l1
    endloop:
        mov ah, 2
        mov dl, '9'
        sub dl, cl
        inc dl
        ; inc dl
        ; add dl, '1'
        int 33
        mov ah, 76
        int 33
main endp
    end main
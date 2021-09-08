.model small
.stack 100h
.data
.code
main proc
    mov cl, 10
    mov ch, 0
    l1:
        mov ah, 1
        int 33
        cmp al, 'a'
        loopz endloop
        mov ah, 2
        mov dl, al
        inc dl
        int 33
        loop l1
    endloop:
        mov ah, 76
        int 33
main endp
    end main
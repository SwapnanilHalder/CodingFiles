.model small
.stack 100h
.data
.code
main proc
    mov ah, 1
    int 33
    mov cl, 10
    mov ch, 0
    mov dl, al
    mov ah, 2
    l1:
        int 33
        loop l1
    mov ah, 76
    int 33
main endp
    end main
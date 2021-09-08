.model small
.stack 100h
.data
.code
main proc
    mov cl, 9
    mov ch, 0
    mov ah, 1
    mov dl, '0'
    l1:
        int 33
        cmp al, 'a'
        jne l2
        add dl, 1
        l2: loop l1
    mov ah, 2
    int 33
    mov ah, 76
    int 33
main endp
    end main
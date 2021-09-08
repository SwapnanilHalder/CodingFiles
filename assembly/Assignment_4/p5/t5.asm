.model small
.stack 100h
.data
.code
;description
main PROC
    mov ah, 1
    int 33
    mov ah, 2
    sub al, '0'
    mov cl, al
    xor ch, ch
    mov dl, 'k'
    cmp al, 0
    loopz skip
    inc cl
    loopy:
        int 33
        loopnz loopy
    skip:
    mov ah, 76
    int 33
main ENDP
    end main
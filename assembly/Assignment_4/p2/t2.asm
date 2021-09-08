.model small
.stack 100h
.data
.code
;description
main PROC
    mov cl, 5
    xor ch, ch
    l1:
        mov ah, 1
        int 33
        inc al
        mov dl, al
        mov ah, 2
        int 33
        loop l1
    mov ah, 76
    int 33 
main ENDP   
    end main
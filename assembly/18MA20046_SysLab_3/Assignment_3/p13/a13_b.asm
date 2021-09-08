.model small
.code
mov dl, 'A'
mov cl, 6
mov ah, 2  ; print mode
L1:
    int 33
    sub cl, 1
    CMP cl, 0
JG L1
mov ah, 76
int 33
END
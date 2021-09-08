.model small
.code
mov ah, 2
mov dl, 'A'
mov cl, 1
L1:
    int 33
    add dl, cl
    add cl, 1
    CMP cl, 6
JLE L1
mov ah, 76
int 33
END
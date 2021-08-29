.model small
.code
mov ah, 1
int 33
mov dl, al
int 33
add dl, al
mov ah, 2
int 33
mov ah, 76
int 33
END
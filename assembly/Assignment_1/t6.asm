.model small
.code
mov ah, 1
int 33
mov dl, al
sub dl, '0'
int 33 ; input
mov ah, 2
add dl, al
int 33
mov ah, 76
int 21h
END
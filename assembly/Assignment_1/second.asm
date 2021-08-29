.model small
.code
mov ah, 1
int 33
mov ah, 2
mov dl, al
sub dl, 48
add dl, dl
add dl, 48
int 33
mov ah, 76
int 33
END
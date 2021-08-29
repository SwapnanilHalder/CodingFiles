
.model small
.code
MOV ah, 1
int 33
mov ah, 2
mov dl, al
add dl, dl
int 33
mov ah, 76
int 33
END
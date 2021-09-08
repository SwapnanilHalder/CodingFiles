.model small
.code

mov ah, 2
mov dx, 12867
int 33
mov dh, dl
int 33
mov ah, 76
int 33
end
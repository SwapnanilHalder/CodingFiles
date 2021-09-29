.model small
.code
mov ah,1
int 33
sub al,80
cbw
mov bx,122
imul bx
mov bx,500
idiv bx
add al,75
mov dl,al
mov ah,2
int 33
mov ah,76
int 33
end
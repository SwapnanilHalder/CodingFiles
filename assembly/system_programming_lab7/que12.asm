.model small
.code
mov ah,1
int 33
sub al,80
mov bl,100
imul bl
mov bx,ax
mov dx,1
mov ax,34464
idiv bx
mov dl,al
add dl,75
mov ah,2
int 33
mov ah,76
int 33
end
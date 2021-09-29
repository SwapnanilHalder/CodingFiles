.model small
.code
mov ah,1
int 33
sub al,80
cbw
mov bx,ax
mov dx,-2
mov ax,31072
idiv bx
add dl,75
mov ah,2
int 33
mov ah,76
int 33
end
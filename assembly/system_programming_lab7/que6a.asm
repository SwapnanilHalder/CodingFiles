.model small
.code
mov ah,1
int 33
sub al,80
mov bl,al
mov ax,1000
idiv bl
mov dl,al
mov bl,ah
add dl,75
add bl,75
mov ah,2
int 33
mov dl,bl
int 33
mov ah,76
int 33
end
.model small
.code
mov ah,1
int 33
sub al,80
mov bl,al
mov ax,1000
idiv bl
cbw
mov bl,50
idiv bl
mov dl,ah
add dl,75
mov ah,2
int 33
mov ah,76
int 33
end
.model small
.code
mov ah,1
int 33
sub al,80
mov bl,al
mov ah,bl
mov al,0
mov bl,100
idiv bl
mov dl,al
add dl,75
mov bl,ah
mov ah,2
int 33
mov dl,bl
add dl,75
int 33
mov ah,76
int 33
end
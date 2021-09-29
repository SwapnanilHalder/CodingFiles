.model small
.code
mov ah,1
int 33
sub al,80
mov bl,100
imul bl
mov dl,ah
mov bl,al
add dl,75
add bl,75
mov ah,2
int 33
mov dl,bl
int 33
mov ah,76
int 33
end
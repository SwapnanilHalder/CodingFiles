.model small
.code
mov ah,1
int 33
sub al,80
cbw
mov bl,6
idiv bl
mov dl,al
add dl,75
mov bl,Ah
add bl,75
mov ah,2
int 33
mov dl,bl
int 33
mov ah,76
int 33
end
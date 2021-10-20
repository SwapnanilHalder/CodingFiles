.model small
.code
Mov AH,1
int 33
mov dl,al
int 33
cmp dl,al
db 01111111b
db 2d
xchg dl,al
L:Mov AH,2
int 33
Mov AH,76
int 33
end
.model small
.code
Mov AH,1
int 33
db 11111110b
db 11000000b
mov dl,al
Mov AH,2
int 33
Mov AH,76
int 33
end
.model small
.code
Mov AH,1
int 33
Mov DL,65
db 00111100b
db 100d
JG L
Inc DL
L:Mov AH,2
int 33
Mov AH,76
int 33
end
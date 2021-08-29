.model small
.code
MOV ah,1
int 33
MOV cl,al
int 33
MOV ah,2
sub cl,al
MOV dl,'-'
int 33
MOV bl,cl
add dl,3
sub dl,bl
int 33
MOV ah,76
int 33
END
.model small
.code
MOV ah,1 ; input mode
int 33

MOV dl,al
sub dl,48

int 33
MOV ah,2 ; print mode

add dl,al
sub dl,10
MOV cl,dl
MOV dl,49
int 33

MOV dl,cl
int 33

MOV ah,76
int 33

END
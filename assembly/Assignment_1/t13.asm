.model small
.code
MOV ah,1 ; input mode
int 33  
MOV bl,al
int 33

MOV ah,2 ; print mode
Sub bl,al
MOV dl,0
Adc dl,65
int 33

MOV ah,76
int 33
END
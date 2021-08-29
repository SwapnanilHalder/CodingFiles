.model small
.code
MOV ah,1
int 33
MOV ah,2
MOV bl,al
Add bl,156
MOV dl,0
Adc dl,65
int 33
MOV ah,76
int 33
END
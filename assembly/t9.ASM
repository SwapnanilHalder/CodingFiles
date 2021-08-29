.model small
.code
MOV AH,1 ; print mode
int 33

MOV AH,2
MOV CL,AL
Add CL,156
MOV DL,0
Adc DL,65
int 33
MOV AH,76
int 33
END
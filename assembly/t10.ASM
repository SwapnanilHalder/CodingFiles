.model small
.code
Mov AH,1
Int 33
Mov CL,AL
Add CL,156
Mov AH,2
Mov DL,0
Adc DL,DL
Add DL,DL
Add DL,65
Int 33
Mov AH,76
Int 33
End
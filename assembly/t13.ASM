.model small
.code
Mov AH,1
Int 33
Mov CL,AL
Int 33
Sub CL,AL
Mov AH,2
Mov DL,0
Adc DL,65
Int 33
Mov AH,76
Int 33
End
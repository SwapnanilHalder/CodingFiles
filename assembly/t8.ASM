.model small
.code
Mov AH,1
Int 33
Mov CL,AL
Int 33
Sub CL,AL
Mov AH,2
Mov DL,45
Int 33
Mov BL,CL
Add DL,3
Sub Dl,BL
Int 33
Mov AH,76
Int 33
End
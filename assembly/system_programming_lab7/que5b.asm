.model small
.code
Mov Ah,1
Int 33
Sub AL,80
Mov BL,-13
IMUL BL
Add AX,75
Mov AH,0
Mov DL,AL
Mov AH,2
Int 33
Mov AH,76
Int 33
end
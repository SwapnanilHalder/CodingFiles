.model small
.code
Mov  AH,2
Mov  DL,82
Int     33   ; <---- print 'R'
mov CX,12
Mov  DL,97
L:int 33
add dl,1
loop L
; Int     33   ; <---- print 'a'
; Mov  DL,13   ; removing 4 by 8, erases DIAMOND ; replacing 4 by 13 => 'ma'
Mov DL,9
Int     33   ; <---- print diamond
Mov  DL,'m'
Int     33   ; <---- print 'm'
Mov  AH,76
Int     33
END
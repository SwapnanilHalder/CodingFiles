; .model small
; .code
; MOV ah, 1
; int 33
; MOV cl, al
; MOV dl, al
; int 33 ; scan
; MOV ah, 2
; int 33 ; print
; MOV dl, cl
; int 33
; MOV ah, 76
; int 33
; END

.model small
.code
MOV ah,1
int 33
MOV cl,al
int 33
MOV dl,al
MOV ah,2
int 33
MOV dl,cl
int 33
MOV ah,76
int 33
END
; .model small
; .code
; mov ah, 2
; mov dl, 'U'
; int 33
; mov dl, ' '
; int 33
; int 33
; int 33
; int 33
; int 33
; int 33
; mov dl, 'H'
; int 33
; mov ah, 76
; int 33
; END

.model small
.code
mov ah,2
mov dl,85
int 33
mov dl,9
int 33
mov dl,8
int 33
mov dl,71
int 33
mov ah,76
int 33
end
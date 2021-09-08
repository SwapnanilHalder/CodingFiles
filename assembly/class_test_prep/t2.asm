.model small
.code
mov ah, 2
mov dl, 'A'
int 33
mov dl, 'b'
int 33
mov dl, 'c'
int 33
mov dl, 'd'
int 33
mov dl, 'e'
int 33
mov dl, 0AH
int 33
; mov dl, 'f'
; int 33
mov dl, 'r'
int 33
mov dl, 'c'
int 33
mov dl, 'd'
int 33
mov dl, 'e'
int 33
; mov dl, 0DH
; int 33
mov dl, 'g'
int 33
mov ah, 76
int 33
end


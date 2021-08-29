.model small
.code
mov ah, 1   ; input mode
mov bl, 0
int 33

mov ah, 2   ; print mode
mov cl, al
sub cl, 111
adc bl, 0
mov cl, al
sub cl, 100
adc bl, 0
mov dl, 'C'
sub dl, bl
int 33

mov ah, 76  ;  end mode
int 33
END

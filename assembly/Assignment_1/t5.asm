.model small
.code
mov ah, 1 ; INPUT MODE
int 33
mov bl, al ; first var
int 33
mov cl,al ; second var
int 33
mov ch,al ; third var
int 33
mov dl,al ; fourth var
mov ah,2
int 33 
mov dl,ch
int 33
mov dl,cl
int 33
mov dl,bl
int 33
mov ah,76
int 33
End
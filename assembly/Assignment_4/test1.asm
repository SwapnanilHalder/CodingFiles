.model small
.code
    mov ah, 1
    mov dl, 6
    mov bl, 0
    loopy: 
        dec dl
        cmp dl, 0
        je endloop
        int 33
        cmp al, bl
        jbe loopy
        mov bl, al
        jmp loopy
    
    endloop :
        mov dl, bl
        mov ah, 2
        int 33
        mov ah, 76
        int 33
        end

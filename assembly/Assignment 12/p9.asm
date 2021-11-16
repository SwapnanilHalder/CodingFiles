.model small
.code
main proc
    mov ah,1
    int 33
    mov dl,al
    mov bh,200
    mov bl,100
    test bh,bl
    adc dl,0
    mov ah,2
    int 33
    mov ah,76
    int 33
main endp
    end main
.model small
.code
main proc
    mov dl,66
    mov ah,1
    int 33
    add al,150
    mov cl,0
    adc cl,0
    sub dl,cl
    mov ah,2
    int 33
    mov ah,76
    int 33
main endp
    end main
.model small
.code
main proc
    mov dl,65
    mov ah,1
    int 33
    add al,150
    adc dl,0
    mov ah,2
    int 33
    mov ah,76
    int 33
main endp
    end main
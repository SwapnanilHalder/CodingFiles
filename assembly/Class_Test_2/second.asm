.model small
.data
    h db 119, 101, 115, 100, 121, 109, 104, 99, 36
.code
    mov ax, @data
    mov dl, 'K'
    mov ds, ax
    mov ah, 9
    mov DX, offset h        ; mov ah, 2
    int 33
    mov ah, 76
    int 33
end


; ; .model small
; ; .data
; ;     h db 119, 101, 115, 100, 121, 109, 104, 99  ; wesdymhc

; ; .code
; ;     MOV ax, @data
; ;     mov ds, ax
; ;     lea dx, h           ; load address of h
; ;     ; mov dx, offset h
; ;     mov ah, 09h
; ;     int 33
; ;     mov ah, 76
; ;     int 33
; ; end


; ; .model small
; ; .data
; ;     a db 66, 69, 80, 72

; ; .code
; ;     MOV ax, @data
; ;     mov ds, ax
; ;     lea dx, a
; ;     mov ah, 9
; ;     add dx, 1
; ;     mov si, dx
; ;     int 33
; ;     mov ah, 76
; ;     int 33
; ; end

; .model small
; .data
;     y db 116, 117, 113, 115, 100, 121, 115 , 36
; .code
; mov ax, @data
; mov dl, 65
; mov ds, ax
; mov ah, 9
; Mov DX, offset y
; int 33
; mov ah, 76
; int 33
; end
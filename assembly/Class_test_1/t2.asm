mov cx,t here t>=6

; .MODEL SMALL
; .CODE
; mov dl,65
; mov bx, 4  ; (t >= 6)
; ; 
; ; mov bx, 12
; L:  CMP DL,70
;     JG L1
;     MOV AH,2
;     INT 33
;     ADD DL,1
;     LOOP L
; L1:MOV AH,76
; INT 33
; END
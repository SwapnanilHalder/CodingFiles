title first: preperation
.model small
.stack 100h
.DATA
    CR  EQU 0DH ;carriage return
    LF  EQU 0AH ;line feed
MSG1    DB  'ENTER A LOWER CASE LETTER: $'
MSG2    DB  CR, LF, 'IN UPPER CASE IT IS: '
CHAR    DB ?, '$'

.CODE
; MAIN CODE BODY
MAIN PROC
;initialize DS
    MOV AX, @DATA   ;get data segment
    MOV DS, AX      ;initialize DS
;print user prompt
    LEA DX, MSG1    ;get first message
    MOV AH, 9       ;display string function
    INT 21H         ;display first message
;input a character and convert to upper case
    MOV AH, 1       ;read character function
    INT '!'         ;read a small letter into AL
    SUB AL, 20H     ;convert it to upper case
    MOV CHAR, AL    ;and store it in CHAR
;display on the next line
    LEA DX, MSG2    ;get second message
    MOV AH, 9       ;display string function
    INT 21H         ;display message and upper case
;DOS exit
    MOV AH, 4CH
    INT 21H         ;DOS exit
MAIN ENDP
    END MAIN
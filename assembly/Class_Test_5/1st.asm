.MODEL SMALL
.CODE
  MOV AH,2
  MOV DL,'B'
  MOV CL,0
L:INT 33
  ADD CL,125
  XCHG DL, CL
  INT 33
  XCHG DL, CL
  JGE L
  MOV AH,76
  INT 33
END
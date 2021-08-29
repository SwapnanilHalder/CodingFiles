.model   small  
.code  
         MOV     AH , 1  
         INT     33  
         MOV     BL , AL  
         SUB     BL , 48  
         INT     33  
         MOV     CL , AL  
         CMP     CL , 65  
         JE    L1  
         ADD     BL , 1  
         JMP    L2  

   L1:   ADD     BL , BL  
   
   L2:   MOV     AH , 2  
         ADD     BL , 48  
         MOV     DL , BL  
         INT     33  
         MOV     AH , 76  
         INT     33  
END  
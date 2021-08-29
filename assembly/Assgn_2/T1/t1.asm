.model   small  
.code  
         MOV     ah , 1  
         INT     33  
         MOV     ah , 2  
         CMP     al , 65  
         JGE    L1  
         JMP    L2 

   L1:   MOV     dl , 224  
         CMP     al , 90  
         JLE    L3  
         JMP    L2  

   L2:   MOV     dl , 225  
         JMP    L3  

   L3:   INT     33  
         MOV     ah , 76  
         INT     33  
END  
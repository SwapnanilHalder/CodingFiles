.model   small  
.code  
         MOV     AH , 1  
         INT     33  
         MOV     BL , AL  
         INT     33  
         MOV     AH , 2  
         MOV     CL , AL  
         CMP     BL , CL  
         JGE    L1  
         JMP    L2  

   L1:   SUB     BL , CL  
         ADD     BL , 48  
         MOV     DL , BL  
         JMP    L3  

   L2:   MOV     DL , 45  
         INT     33  
         SUB     CL , BL  
         ADD     CL , 48  
         MOV     DL , CL  
         
   L3:   INT     33  
         MOV     AH , 76  
         INT     33      
END  
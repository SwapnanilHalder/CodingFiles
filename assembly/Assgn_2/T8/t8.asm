.model   small  
.code  
         MOV     AH , 1  
         INT     33  
         MOV     BL , AL  
         INT     33  
         MOV     CL , AL  
         SUB     BL , CL  
         CMP     BL , 9  
         JG    L1  
         ADD     BL , 48  
         MOV     DL , BL  
         JMP    L2 

   L1:   SUB     BL , 10  
         ADD     BL , 65  
         MOV     DL , BL  
         
   L2:   MOV     AH , 2  
         INT     33  
         MOV     AH , 76  
         INT     33  
END  
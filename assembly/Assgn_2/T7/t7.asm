.model   small  
.code  
         MOV     AH , 1  
         INT     33  
         MOV     BL , AL  
         INT     33  
         MOV     CL , AL  
         CMP     CL , 65  
         JGE    L1  
         SUB     CL , 48  
         ADD     BL , CL  
         MOV     DL , BL  
         JMP    L2 

   L1:   SUB     CL , 64  
         ADD     CL , 9  
         ADD     BL , CL  
         MOV     DL , BL 

   L2:   MOV     AH , 2  
         INT     33  
         MOV     AH , 76  
         INT     33  
END  
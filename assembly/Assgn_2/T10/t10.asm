.model   small  
.code  
         MOV     AH , 1  
         INT     33  
         MOV     BL , AL  
         INT     33  
         MOV     CL , AL  
         CMP     BL , CL  
         JGE    L1  
         MOV     DL , CL  
         JMP    L2  

   L1:   MOV     DL , BL
     
   L2:   MOV     AH , 2  
         INT     33  
         MOV     AH , 76  
         INT     33  
END
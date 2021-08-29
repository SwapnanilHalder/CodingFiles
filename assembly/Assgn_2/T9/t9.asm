.model   small  
.code  
         MOV     AH , 1  
         INT     33  
         MOV     CL , 0  
         CMP     AL , 97  
         JGE    L1  
         MOV     CL , 1  

   L1:   ADD     CL , 224  
         MOV     DL , CL  
         MOV     AH , 2  
         INT     33  
         MOV     AH , 76  
         INT     33  
END 
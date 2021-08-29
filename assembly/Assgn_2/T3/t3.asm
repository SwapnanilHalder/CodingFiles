.model   small  
.code  
        MOV     AH , 1  
        INT     33  
        CMP     AL , 65  
        JGE    L1  
        MOV     DL , 225  
        JMP    L4 

   L1:   MOV     BL , AL  
        SUB     BL , 65  
        CMP     BL , 25  
        JGE    L2  
        MOV     DL , 224  
        JMP    L4  

   L2:   MOV     BL , AL  
        CMP     BL , 97  
        JGE    L3  
        MOV     DL , 225  
        JMP    L4  

   L3:   MOV     DL , 224  
        CMP     BL , 122  
        JLE    L4  
        MOV     DL , 225  

   L4:   MOV     AH , 2  
        INT     33  
        MOV     AH , 76  
        INT     33  
END         
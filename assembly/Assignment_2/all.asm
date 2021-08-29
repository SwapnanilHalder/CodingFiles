Solution   1  

.model   small  
.code  
      MOV     AH , 1  
      INT     33  
      MOV     AH , 2  
      CMP     AL , 65  
      JGE    L1  
      JMP    L2  
   L1:   MOV     DL , 224  
      CMP     AL , 90  
      JLE    L3  
      JMP    L2  
   L3:   JMP    L4  
   L2:   MOV     DL , 225  
      JMP    L4  
   L4:   INT     33  
      MOV     AH , 76  
      INT     33  
END  


Solution   2  

.model   small  
.code  
      MOV     AH , 1  
      INT     33  
      MOV     AH , 2  
      CMP     AL , 97  
      JGE    L1  
      JMP    L2  
   L1:   MOV     DL , 224  
      JMP    L4  
   L2:   MOV     DL , 226  
      CMP     AL , 65  
      JL    L3  
      JMP    L5  
   L3:   JMP    L4  
   L5:   MOV     DL , 225  
      JMP    L4  
   L4:   INT     33  
      MOV     AH , 76  
      INT     33  
END  

Solution   3  

.model   small  
.code  
      MOV     AH , 1  
      INT     33  
      CMP     AL , 65  
      JGE    L1  
      MOV     DL , 225  
      JMP    L3  
   L1:   MOV     BL , AL  
      SUB     BL , 65  
      CMP     BL , 25  
      JGE    L2  
      MOV     DL , 224  
      JMP    L3  
   L2:   MOV     BL , AL  
      CMP     BL , 97  
      JGE    L4  
      MOV     DL , 225  
      JMP    L3  
   L4:   MOV     DL , 224  
      CMP     BL , 122  
      JLE    L3  
      MOV     DL , 225  
   L3:   MOV     AH , 2  
      INT     33  
      MOV     AH , 76  
      INT     33  
END          

Solution   4  

.model   small  
.code  
         MOV     AH , 1  
         INT     33  
         MOV     BL , AL  
         INT     33  
         MOV     CL , AL  
         CMP     BL , CL  
         JGE    L1  
         SUB     CL , BL  
         ADD     CL , 48  
         MOV     DL , CL  
         JMP    L2  

   L1:   SUB     BL , CL  
         ADD     BL , 48  
         MOV     DL , BL 

   L2:   MOV     AH , 2  
         INT     33  
         MOV     AH , 76  
         INT     33  
END  

Solution   5  

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


Solution   6  

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

Solution   7  

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



Solution   8  

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

Solution   9  

.model   small  
.code  
         MOV     AH , 1  
         INT     33  
         MOV     BL , 0  
         CMP     AL , 97  
         JGE    L1  
         MOV     BL , 1  

   L1:   ADD     BL , 224  
         MOV     DL , BL  
         MOV     AH , 2  
         INT     33  
         MOV     AH , 76  
         INT     33  
END  






Solution   10  

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
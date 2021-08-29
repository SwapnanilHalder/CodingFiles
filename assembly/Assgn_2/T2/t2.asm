.model   small  
.code  
         mov     ah , 1  
         int     21h  
         mov     ah , 2  
         cmp     al , 97  
         JGE    l1  
         jmp    l2 

   l1:   mov     dl , 224  
         jmp    l4 

   l2:   mov     dl , 226  
         cmp     al , 65  
         JL    l3  
         jmp    l5  

   l3:   jmp    l4  

   l5:   mov     dl , 225  
         jmp    l4  

   l4:   int     21h  
         mov     ah , 76  
         int     21h  
end  
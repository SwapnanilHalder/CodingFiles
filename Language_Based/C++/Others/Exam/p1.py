def fill(arr,i):    
    m1,m2,m3 = 0,0,0
    c1,c2,c3 = "a","a","a"
    
    gm = 0
    gc = "a"
    
    if i-2 >=0:
        ca = 0
        cb = 0
        
        for j in range(i-2, i+1):
            if arr[j] == "a":
                ca+=1
            elif arr[j] == "b":
                cb+= 1
                
        if ca < cb:
            arr[i] = "a"
            # print(arr)
            return arr
        else:
            arr[i] = "b"
            # print(arr)
            return arr
        
        
    if i-1 >=0 and i+1 < len(arr):
        ca = 0
        cb = 0
        
        for j in range(i-1, i+2):
            if arr[j] == "a":
                ca+=1
            elif arr[j] == "b":
                cb+= 1
        if ca < cb:
            arr[i] = "a"
            # print(arr)
            return arr
        else:
            arr[i] = "b"
            # print(arr)
            return arr
            
    if i+2 < len(arr):
        ca = 0
        cb = 0
        
        for j in range(i, i+3):
            if arr[j] == "a":
                ca+=1
            elif arr[j] == "b":
                cb+= 1
        if ca < cb:
            arr[i] = "a"
            # print(arr)
            return arr
        else:
            arr[i] = "b"
            # print(arr)
            return arr
    
    arr[i] = "a"
    # print(arr)    
    return arr
    
def calMax(arr,i):    
    m1,m2,m3 = 0,0,0
    c1,c2,c3 = "a","a","a"
    
    gm = 0
    gc = "a"
    
    if i-2 >=0:
        ca = 0
        cb = 0
        
        for j in range(i-2, i+1):
            if arr[j] == "a":
                ca+=1
            elif arr[j] == "b":
                cb+= 1
                
        if ca < cb:
            c1 = "b"
            m1 = cb
            gm = cb
            gc = "b"
        else:
            m1 = ca
            gm = ca
        
        
    if i-1 >=0 and i+1 < len(arr):
        ca = 0
        cb = 0
        
        for j in range(i-1, i+2):
            if arr[j] == "a":
                ca+=1
            elif arr[j] == "b":
                cb+= 1
        if ca < cb:
            c2 = "b"
            m2 = cb
            
        else:
            m2 = ca
        
        if m2 > gm:
            gm = m2
            gc = c2
            
    if i+2 < len(arr):
        ca = 0
        cb = 0
        
        for j in range(i, i+3):
            if arr[j] == "a":
                ca+=1
            elif arr[j] == "b":
                cb+= 1
        if ca < cb:
            c3 = "b"
            m3 = cb
        else:
            m3 = ca
            
        if m3 > gm:
            gm = m3
            gc = c3
        
    return gm,gc
def main():
    s = "aa??aa"
    
    s = list(map(str, s))
    for i in range(len(s)):
        if s[i] == "?":
            count, c = calMax(s,i)
            
            if count == 2:
                if c == "a":
                    s[i] = "b"
                else:
                    s[i] = "a"
    # print("".join(s))
    
    for i in range(len(s)):
        if s[i] == "?":
            l = fill(s,i)
            
    print("".join(s)) 
    
main()
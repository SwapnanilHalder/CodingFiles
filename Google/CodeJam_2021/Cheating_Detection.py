t = int(input())
for i in range(t):
    p = int(input())
    maxm = -1
    maxm_ind = -1
    for p in range(100):
        s = input()
        counts = 0
        for j in s:
            if (j == '1') :
                counts += 1
        if(counts > maxm) :
            maxm = counts 
            maxm_ind = p+1
    print("Case #" , i+1, ": ",maxm_ind, sep="")

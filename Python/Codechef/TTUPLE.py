import numpy as np
def answer(a,b,count):
    if (a==b).all():
        print(count)
        return
    if(sum(a==b) == 2):
        idx = np.where((a !=b) )[0][0]
        a[idx] = b[idx]
        count += 1
    if(sum(a==b) == 1):
        if(len(np.unique(b-a)) == 2 or len(np.unique(b/a)) == 2):
            a[np.where((a !=b))] = b[np.where((a !=b))]
            count += 1
        else :
            a[np.where((a !=b))] = b[np.where((a !=b))]
            count += 2
    else:
        if(len(np.unique(b-a)) == 1 or len(np.unique(b/a)) == 1):
            a[np.where((a !=b))] = b[np.where((a !=b))]
            count += 1
    
    answer(a, b, count)

t = int(input())
for z in range(t):
    count = 0
    inp = input()
    a = np.array(list(map(int, inp.split(' '))))
    inp = input()
    b = np.array(list(map(int, inp.split(' '))))
    #answer(a,b, count)
    
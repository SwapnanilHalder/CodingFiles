t = int(input())
for i in range(t):
    k = int(input())
    d = {}
    end = 1
    inp = input()
    inp = list(map(int, inp.split()))
    for j in range(k):
        if (inp[j-1] != inp[j]) and (inp[j] in d.keys()):
            end = 0
            break
        try:
            d[inp[j]] += 1
        except KeyError :
            d[inp[j]] = 1
    if len(d.values()) != len(set(d.values())):
        end = 0
    if end == 0:
        print('NO')
    if end == 1:
        print('YES')
    
    
    
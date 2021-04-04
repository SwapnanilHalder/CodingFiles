t = int(input())
for i in range(t):
    n = int(input())
    inp = input()
    a = list(map(int, inp.split(' ')))
    even = 0
    odd = 0
    for i in range(len(a)):
        if(i%2 != a[i]%2):
            if(i%2 == 0):
                even += 1
            else:
                odd += 1
    if(even == odd):
        print(int(even))
    else:
        print("-1")
    
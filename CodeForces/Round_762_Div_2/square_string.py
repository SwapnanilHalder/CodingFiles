t = int(input())
for i in range(0, t):
    s = input()
    n = len(s)
    if(n&1) :
        print("NO")
    else:
        if(s[:int(n/2)] == s[int(n/2):]):
            print("YES")
        else:
            print("NO")

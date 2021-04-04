t = int(input())
for i in range(t):
    a = input()
    j = 1
    l = len(a)
    while j <= l:
        a = a[:j+1] + a[j+2:]
        j += 1
        l -= 1
    print(a)
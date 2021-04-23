t = int(input())
for _ in range(t):
    x = int(input())
    if (x % 2050 != 0) :
        print("-1")
    else :
        div = int(x/2050)
        # print(div)
        total = 0
        while(div > 0) :
            total += div % 10
            div = int(div/10)
            # print(total)
        print(int(total))

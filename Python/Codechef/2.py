k = int(input())
for j in range(k):
    str = input()
    d = {}
    temp =''
    for i in range(len(str)):
        temp +=str[i]
        if (len(temp) != 0) and (len(temp) % 2 ==0):
            b = int(len(temp) / 2)
            if (temp[:b] == temp[b:]):
                try :
                    d[temp[:b]] += len(temp)
                except KeyError:
                    d[temp[:b]] = len(temp)
                temp = ''
                
    if(sum(d.values()) != len(str)):
        print(0)
    else:
        count = d.copy()
        for x in count.keys():
            count[x] = int((count[x] / 2) / len(x))
        print(sum(count.values()) - 1)

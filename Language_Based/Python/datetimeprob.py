from datetime import datetime
arr = []
time = []
dist = []
cont = 1
while(cont):
    x = input()
    if x == '' :
        cont = 0
        break
    else :
        a, b = x.split()
        b = float(b)
        date_obj = datetime.strptime(a, '%H:%M:%S.%f')
        time.append(date_obj)
        dist.append(b)

for x in time:
    print(x)



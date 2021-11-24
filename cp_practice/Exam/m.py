'''
# Sample code to perform I/O:

name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

# Write your code here

from collections import defaultdict

l = []
d = defaultdict(list)

def add(user):
    if user in l:
        print("failure")
    else:
        l.append(user)
        print("success")

def event(date, start, duration, numu, lusers, d):
    l3 = date.split("-")
    if start + duration > 1440:
        print("failure")
        return
    if start < 0:
        print("failure")
        return

    if len(l3[0]!= 4 or len(l3[1])!=2 or len(l3[2])!=2):
        print("failure")
        return

    x = d.copy()

    for i in range(numu):
        x[date].append([lusers, start, start+duration])

    z1 = []

    for i in x[date]:
        z1.append([i[1], 1])
        z1.append([i[2], -1])

    z1.sort()
    c = 0
    for i in z1:
        c += z1[1]
        if c>1:
            print("failure")
            return

    print("success")

    d = x.copy()

def listevents(day, user):
    if not day in d.keys():
        print("none")
        return

    x = d[day]

    c = 0

    for i in x:
        if user in i[0]:
            print(i[1]+"-"+i[2], end=" ")
            print(*i[0])
            c = 1

    if c==0:
        print("none")

def suggestslot(date, start, end, duration, numu, lusers):
    query = d[date]
    ans = start

    if start+duration < end:
        print("none")
        return
    f = []

    for i in range(1440):
        f.append(0)

    for q in query:
        for user in lusers:
            if user in q[0]:
                for i in range(q[1], q[2]):
                    f[i] += 1
                
    for i in range(len(f)):
        if f[i] == 0:
            c = 0
            for j in range(duration):
                if f[i+j] != 0:
                    c = 1
                    break
            if c == 0:
                ans = i
                break

    print(ans)
        
num = input()

for a in range(int(num)):
    s = input()
    if "add-user" in s:
        x = s.split(" ")
        add(x[1])
    if "create-event" in s:
        x = s.split(" ")
        event(x[1], int(x[2]), int(x[3]), int(x[4]), x[5:])
    if "show-events" in s:
        x = s.split(" ")
        listevents(x[1], x[2])
    if "suggest-slot" in s:
        x = s.split(" ")
        suggestslot(x[1], int(x[2]), int(x[3]), int(x[4]), int(x[5]), x[6:])
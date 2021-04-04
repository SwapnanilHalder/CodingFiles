import timeit
code_to_test = """
rooms = int(input())
tv, notv = list(map(int, input().split(' ')))
target = int(input())
monthday = [31,28, 31,30,31,30,31,31,30,31,30,31]
patients = []
for month in range(1, 13):
    for day in range(1, monthday[month-1]+1):
        people = (6-month)**2 + abs(day-15)
        patients.append(people)

revenue = 0
notvp = rooms
tvp = 0
while(revenue < target and notvp >=0 and tvp >=0):
    revenue = 0
    for i in range(len(patients)):
        if(patients[i] < rooms) :
            if (notvp >= patients[i]):
                notvspent = patients[i] * notv
                tvspent = 0
            else:
                notvspent = notvp * notv
                tvspent = (patients[i] - notvp) * tv
            revenue += (notvspent + tvspent)
        elif(patients[i] >= rooms):
            notvspent = notvp * notv
            tvspent = tvp * tv
            revenue += (notvspent + tvspent)
    notvp -= 1
    tvp += 1
print(tvp-1) 
"""
elapsed_time = timeit.timeit(code_to_test, number = 1)/100
print(elapsed_time)
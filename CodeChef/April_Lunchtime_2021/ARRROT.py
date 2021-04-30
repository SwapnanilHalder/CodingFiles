n = int(input())
arr = list(map(int, input().split(' ')))
total = sum(arr, 0)
q = int(input())
queries = list(map(int, input().split(' ')))
for i in range(q):
    total *= 2
    print(total % 1000000007)
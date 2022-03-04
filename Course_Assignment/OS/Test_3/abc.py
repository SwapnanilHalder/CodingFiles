def generator1(n) :
    for i in range(n):
        yield i

def generator2(x, y):
    for j in range(x, y):
        yield j

def generator3(n, m):
    yield from generator1(n)
    yield from generator2(n, m+3)

print(tuple(generator2(4, 10)))
from itertools import product

n = int(input())
m = int(input())

numbres = [i for i in range(0, 10)]
if m == 0:
    min = len(list(str(n)))
else:
    arr = list(map(int, input().split()))
    for i in arr:
        numbres.remove(i)
    min = 500000
    for rep in range(1, len(list(str(n)))+2):
        for a in list(product(numbres, repeat=rep)):
            num = ''
            for i in a:
                num += str(i)
            num = int(num)
            if min > abs(n - num) + len(list(str(num))):
                min = abs(n - num) + len(list(str(num)))

print(min if min < abs(100 - n) else abs(100 - n))
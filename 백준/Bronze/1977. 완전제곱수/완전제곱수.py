n = int(input())
m = int(input())


def sqrt(n: int):
    return int(n ** 0.5)


square = [x**2 for x in range(1, 101)]

min = 0
sum = 0
for i in range(n, m+1):
    if i in square:
        if sum == 0:
            min = i
        sum += i
        
if sum == 0:
    print(-1)
else:
    print(sum)
    print(min)
def isPrime(n):
    if n <= 1:
        return False
    for i in range(2, n//2+1):
        if n % i == 0:
            return False
    return True

m = int(input())
n = int(input())

sum = 0
min = 0

for i in range(m, n+1):
    if isPrime(i):
        if min == 0:
            min = i
        sum += i
        
if min == 0:
    print(-1)
else:
    print(sum)
    print(min)

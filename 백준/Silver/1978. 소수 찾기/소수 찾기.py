def isPrime(n):
    if n == 1 :
        return False
    for i in range(2, n // 2 + 1):
        if n % i == 0:
            return False
    return True

n = int(input())
nums = list(map(int, input().split()))

result = 0
for num in nums:
    if isPrime(num):
        result += 1

print(result)
def eratosthenes(n):
    primes = [True] * (n + 1)
    p = 2
    while p * p <= n:
        if primes[p]:
            for i in range(p * p, n + 1, p):
                primes[i] = False
        p += 1
    primes_list = []
    for p in range(2, n):
        if primes[p]:
            primes_list.append(p)
    return primes_list


n = int(input())
result = 1
for p in eratosthenes(n+1):
    tmp = p
    while p * tmp <= n:
        tmp *= p
    result = result * tmp % 987654321
print(result)
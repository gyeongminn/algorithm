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


print(eratosthenes(1000000)[int(input())-1])

def factorize(n):
    result = []
    factor = 2
    while factor * factor <= n:
        while n % factor == 0:
            result.append(factor)
            n = n // factor
        factor += 1
    if n > 1:
        result.append(n)
    return result


n = int(input())
for i in factorize(n):
    print(i)
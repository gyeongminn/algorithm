def getDivisor(n):
    result = []
    for i in range(1, int(n**(1/2)) + 1):
        if (n % i == 0):
            result.append(i)
            if ((i**2) != n):
                result.append(n // i)
    result.sort()
    return result


def solution(n):
    divisors = getDivisor(n)
    if sum(divisors[:-1]) > n:
        for i in divisors[:-1]:
            if sum(getDivisor(i)[:-1]) > i:
                return 'BOJ 2022'
        return 'Good Bye'
    return 'BOJ 2022'


t = int(input())

for _ in range(t):
    n = int(input())
    print(solution(n))

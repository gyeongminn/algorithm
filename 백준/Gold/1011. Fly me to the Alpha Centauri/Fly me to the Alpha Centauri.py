n = int(input())

for _ in range(n):
    x, y = map(int, input().split())
    d = y - x
    
    # d보다 작은 최대의 제곱수 i^2
    i = 0
    while i ** 2 <= d:
        i += 1
    i -= 1
    
    term = 2 * i - 1 + (d - i ** 2 + i - 1) // i
    
    print(term)
    
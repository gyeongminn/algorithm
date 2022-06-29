n = int(input())

for _ in range(n):
    x, y = map(int, input().split())
    d = y - x
    
    # d보다 작은 최대의 제곱수 k^2
    k = 0
    while k ** 2 <= d:
        k += 1
    k -= 1
    
    result = 2 * k - 1 + (d - k ** 2 + k - 1) // k
    
    print(result)
a, b = map(int, input().split())
c = int(input())

if a + b >= 2 * c: 
    ans = a + b - 2 * c
else: 
    ans = a + b
print(ans)
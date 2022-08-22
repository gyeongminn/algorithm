n, m = map(int, input().split())

s = {}
check = [""] * m
result = 0

for _ in range(n):
    s[input()] = 1
    
for i in range(m):
    check[i] = input()
    
for str in check:
    try:
        if s[str] == 1:
            result += 1
    except:
        pass
    
print(result)
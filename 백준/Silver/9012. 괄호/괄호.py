n = int(input())

for _ in range(n):
    arr = list(input())
    s = 0
    for p in arr:
        if p == '(':
            s += 1
        else:
            s -= 1
        if s < 0:
            break
    if s == 0:
        print('YES')
    else:
        print('NO')
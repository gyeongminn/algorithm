t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    cnt = 0
    for i in range(a, b+1):
        for c in str(i):
            if c == '0':
                cnt+= 1
    print(cnt)
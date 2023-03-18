import sys
input = sys.stdin.readline

x, s = 0, 0
m = int(input())
for _ in range(m):
    opt, *n = map(int, input().split())
    if opt == 1:
        s += n[0]
        x ^= n[0]
    elif opt == 2:
        s -= n[0]
        x ^= n[0]
    elif opt == 3:
        print(s)
    else:
        print(x)

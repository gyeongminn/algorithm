n = int(input())

for _ in range(n):
    strings = [list(x) for x in input().split(" ")]
    for s in strings:
        print(*reversed(s), sep='', end=' ')
    print()
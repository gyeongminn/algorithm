import sys
input = sys.stdin.readline

n, m = map(int, input().split())
for _ in range(m):
    size = int(input())
    arr = [int(x) for x in input().split()]
    if arr != list(sorted(arr, reverse=True)):
        print('No')
        exit(0)
print('Yes')

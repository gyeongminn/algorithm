import sys

n, m, b = map(int, sys.stdin.readline().split())
arr = [[0] * m for _ in range(n)]

s = 0
for i in range(n):
    arr[i] = list(map(int, sys.stdin.readline().split()))
    s += sum(arr[i])

min_time = sys.maxsize
height = 0
for target in range(257):
    up = 0
    down = 0
    for row in arr:
        for block in row:
            if block > target:
                up += block - target
            else:
                down += target - block
    if down <= up + b and min_time >= up * 2 + down:
        min_time, height = up * 2 + down, target

print(min_time, height)

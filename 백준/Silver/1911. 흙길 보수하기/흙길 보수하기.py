import sys

n, l = map(int, sys.stdin.readline().split())
arr = sorted([list(map(int, sys.stdin.readline().split())) for _ in range(n)])

count = 0
last = 0

for start, end in arr:
    if start > last:
        last = start
    while end > last:
        count += 1
        last += l

print(count)

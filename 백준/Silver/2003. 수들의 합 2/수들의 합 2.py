import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [int(x) for x in input().split()]

s, e = 0, 1
count = 0
while s <= e and e <= n:
    total = sum(arr[s:e])
    if total < m:
        e += 1
    elif total > m:
        s += 1
    else:
        count += 1
        e += 1
print(count)

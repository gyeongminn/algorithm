import sys

input = sys.stdin.readline

n, m = map(int, input().split())
arr = [[int(x) for x in input().split()] for _ in range(n)]
result = 0

# oooo
for y in range(n):
    for x in range(m-3):
        result = max(result, arr[y][x]+arr[y][x+1]+arr[y][x+2]+arr[y][x+3])
for y in range(n-3):
    for x in range(m):
        result = max(result, arr[y][x]+arr[y+1][x]+arr[y+2][x]+arr[y+3][x])
# oo
# oo
for y in range(n-1):
    for x in range(m-1):
        result = max(result, arr[y][x]+arr[y][x+1] +arr[y+1][x]+arr[y+1][x+1])
# o
# o
# oo
for y in range(n-2):
    for x in range(m-1):
        result = max(result, arr[y][x]+arr[y+1][x]+arr[y+2][x]+arr[y+2][x+1])
for y in range(n-1):
    for x in range(m-2):
        result = max(result, arr[y][x]+arr[y+1][x]+arr[y][x+1]+arr[y][x+2])
for y in range(n-2):
    for x in range(m-1):
        result = max(result, arr[y][x]+arr[y][x+1]+arr[y+1][x+1]+arr[y+2][x+1])
for y in range(n-1):
    for x in range(m-2):
        result = max(result, arr[y+1][x]+arr[y+1][x+1]+arr[y+1][x+2]+arr[y][x+2])
#  o
#  o
# oo
for y in range(n-2):
    for x in range(m-1):
        result = max(result, arr[y][x+1]+arr[y+1][x+1]+arr[y+2][x+1]+arr[y+2][x])
for y in range(n-1):
    for x in range(m-2):
        result = max(result, arr[y][x]+arr[y+1][x]+arr[y+1][x+1]+arr[y+1][x+2])
for y in range(n-2):
    for x in range(m-1):
        result = max(result, arr[y][x]+arr[y+1][x]+arr[y+2][x]+arr[y][x+1])
for y in range(n-1):
    for x in range(m-2):
        result = max(result, arr[y][x]+arr[y][x+1]+arr[y][x+2]+arr[y+1][x+2])
# o
# oo
#  o
for y in range(n-2):
    for x in range(m-1):
        result = max(result, arr[y][x]+arr[y+1][x]+arr[y+1][x+1]+arr[y+2][x+1])
for y in range(n-1):
    for x in range(m-2):
        result = max(result, arr[y+1][x]+arr[y+1][x+1]+arr[y][x+1]+arr[y][x+2])
for y in range(n-1):
    for x in range(m-2):
        result = max(result, arr[y][x]+arr[y+1][x+1]+arr[y][x+1]+arr[y+1][x+2])
for y in range(n-2):
    for x in range(m-1):
        result = max(result, arr[y+1][x]+arr[y][x+1]+arr[y+1][x+1]+arr[y+2][x])

# ooo
#  o
for y in range(n-1):
    for x in range(m-2):
        result = max(result, arr[y][x]+arr[y][x+1]+arr[y][x+2]+arr[y+1][x+1])
for y in range(n-2):
    for x in range(m-1):
        result = max(result, arr[y][x]+arr[y+1][x]+arr[y+2][x]+arr[y+1][x+1])
for y in range(n-1):
    for x in range(m-2):
        result = max(result, arr[y+1][x]+arr[y+1][x+1]+arr[y+1][x+2]+arr[y][x+1])
for y in range(n-2):
    for x in range(m-1):
        result = max(result, arr[y+1][x]+arr[y][x+1]+arr[y+1][x+1]+arr[y+2][x+1])

print(result)

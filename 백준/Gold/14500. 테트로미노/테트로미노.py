import sys

input = sys.stdin.readline

n, m = map(int, input().split())
arr = [[int(x) for x in input().split()] for _ in range(n)]
result = 0

for y in range(n):
    for x in range(m-3):
        if result < arr[y][x]+arr[y][x+1]+arr[y][x+2]+arr[y][x+3]:
            result = arr[y][x]+arr[y][x+1]+arr[y][x+2]+arr[y][x+3]
for y in range(n-3):
    for x in range(m):
        if result < arr[y][x]+arr[y+1][x]+arr[y+2][x]+arr[y+3][x]:
            result = arr[y][x]+arr[y+1][x]+arr[y+2][x]+arr[y+3][x]
for y in range(n-1):
    for x in range(m-1):
        if result < arr[y][x]+arr[y][x+1] +arr[y+1][x]+arr[y+1][x+1]:
            result = arr[y][x]+arr[y][x+1] +arr[y+1][x]+arr[y+1][x+1]
for y in range(n-1):
    for x in range(m-2):
        if result < arr[y][x]+arr[y+1][x]+arr[y][x+1]+arr[y][x+2]:
            result = arr[y][x]+arr[y+1][x]+arr[y][x+1]+arr[y][x+2]
        if result < arr[y][x]+arr[y][x+1]+arr[y][x+2]+arr[y+1][x+1]:
            result = arr[y][x]+arr[y][x+1]+arr[y][x+2]+arr[y+1][x+1]
        if result < arr[y+1][x]+arr[y+1][x+1]+arr[y+1][x+2]+arr[y][x+1]:
            result = arr[y+1][x]+arr[y+1][x+1]+arr[y+1][x+2]+arr[y][x+1]
        if result < arr[y][x]+arr[y+1][x+1]+arr[y][x+1]+arr[y+1][x+2]:
            result = arr[y][x]+arr[y+1][x+1]+arr[y][x+1]+arr[y+1][x+2]
        if result < arr[y+1][x]+arr[y+1][x+1]+arr[y][x+1]+arr[y][x+2]:
            result = arr[y+1][x]+arr[y+1][x+1]+arr[y][x+1]+arr[y][x+2]
        if result < arr[y][x]+arr[y][x+1]+arr[y][x+2]+arr[y+1][x+2]:
            result = arr[y][x]+arr[y][x+1]+arr[y][x+2]+arr[y+1][x+2]
        if result < arr[y][x]+arr[y+1][x]+arr[y+1][x+1]+arr[y+1][x+2]:
            result = arr[y][x]+arr[y+1][x]+arr[y+1][x+1]+arr[y+1][x+2]
        if result < arr[y+1][x]+arr[y+1][x+1]+arr[y+1][x+2]+arr[y][x+2]:
            result = arr[y+1][x]+arr[y+1][x+1]+arr[y+1][x+2]+arr[y][x+2]
for y in range(n-2):
    for x in range(m-1):
        if result < arr[y][x]+arr[y+1][x]+arr[y+2][x]+arr[y+2][x+1]:
            result = arr[y][x]+arr[y+1][x]+arr[y+2][x]+arr[y+2][x+1]
        if result < arr[y][x]+arr[y][x+1]+arr[y+1][x+1]+arr[y+2][x+1]:
            result = arr[y][x]+arr[y][x+1]+arr[y+1][x+1]+arr[y+2][x+1]
        if result < arr[y][x]+arr[y+1][x]+arr[y+2][x]+arr[y+1][x+1]:
            result = arr[y][x]+arr[y+1][x]+arr[y+2][x]+arr[y+1][x+1]
        if result < arr[y+1][x]+arr[y][x+1]+arr[y+1][x+1]+arr[y+2][x+1]:
            result = arr[y+1][x]+arr[y][x+1]+arr[y+1][x+1]+arr[y+2][x+1]
        if result < arr[y+1][x]+arr[y][x+1]+arr[y+1][x+1]+arr[y+2][x]:
            result = arr[y+1][x]+arr[y][x+1]+arr[y+1][x+1]+arr[y+2][x]
        if result < arr[y][x]+arr[y+1][x]+arr[y+1][x+1]+arr[y+2][x+1]:
            result = arr[y][x]+arr[y+1][x]+arr[y+1][x+1]+arr[y+2][x+1]
        if result < arr[y][x]+arr[y+1][x]+arr[y+2][x]+arr[y][x+1]:
            result = arr[y][x]+arr[y+1][x]+arr[y+2][x]+arr[y][x+1]
        if result < arr[y][x+1]+arr[y+1][x+1]+arr[y+2][x+1]+arr[y+2][x]:
            result = arr[y][x+1]+arr[y+1][x+1]+arr[y+2][x+1]+arr[y+2][x]

print(result)

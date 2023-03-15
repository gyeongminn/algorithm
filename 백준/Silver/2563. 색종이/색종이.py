import sys

input = sys.stdin.readline

arr = [[0] * 111 for _ in range(111)]
n = int(input())
for _ in range(n):
    x, y = map(int, input().split())
    for i in range(10):
        for j in range(10):
            arr[i + y][j + x] += 1

count = 0
for i in range(101):
    for j in range(101):
        if arr[i][j] > 0:
            count += 1
print(count)

import sys


def find_max_candy(arr):
    max_candy = 0
    for i in range(n):
        count = 1
        for j in range(n - 1):
            if arr[i][j] == arr[i][j + 1]:
                count += 1
            else:
                max_candy = max(max_candy, count)
                count = 1
        max_candy = max(max_candy, count)
        count = 1
        for j in range(n - 1):
            if arr[j][i] == arr[j + 1][i]:
                count += 1
            else:
                max_candy = max(max_candy, count)
                count = 1
        max_candy = max(max_candy, count)
    return max_candy


input = sys.stdin.readline

n = int(input())
arr = [list(input()) for _ in range(n)]

result = 0

for y in range(n):
    for x in range(n - 1):
        if arr[y][x] != arr[y][x + 1]:
            arr[y][x], arr[y][x + 1] = arr[y][x + 1], arr[y][x]
            result = max(find_max_candy(arr), result)
            arr[y][x], arr[y][x + 1] = arr[y][x + 1], arr[y][x]

for y in range(n - 1):
    for x in range(n):
        if arr[y][x] != arr[y + 1][x]:
            arr[y + 1][x], arr[y][x] = arr[y][x], arr[y + 1][x]
            result = max(find_max_candy(arr), result)
            arr[y + 1][x], arr[y][x] = arr[y][x], arr[y + 1][x]

print(result)

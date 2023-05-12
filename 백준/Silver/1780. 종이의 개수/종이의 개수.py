from math import *
import sys
input = sys.stdin.readline


def check(x, y, k, color):
    for ny in range(y, y+k):
        for nx in range(x, x+k):
            if color != arr[ny][nx]:
                return False
    return True


def mark(x, y, k, color):
    global visited
    for ny in range(y, y+k):
        for nx in range(x, x+k):
            visited[ny][nx] = True


n = int(input())
arr = [[int(x) for x in input().split()] for _ in range(n)]

visited = [[False] * n for _ in range(n)]
res = [0, 0, 0]

k = n
while k:
    size = k * k
    for y in range(0, n, k):
        for x in range(0, n, k):
            if not visited[y][x]:
                color = arr[y][x]
                if check(x, y, k, color):
                    mark(x, y, k, color)
                    res[color] += 1
    k //= 3

print(res[-1], res[0], res[1], sep='\n')

from math import *
import sys
input = sys.stdin.readline

arr = []
n = int(input())
for _ in range(n):
    arr.append([int(x) for x in input().split()])

visited = [[False] * n for _ in range(n)]
res = [0, 0]
for i in range(ceil(log2(n)), -1, -1):
    size = 2 ** i
    for y in range(0, n, size):
        for x in range(0, n, size):
            if not visited[y][x]:
                color = arr[y][x]
                flag = False
                for ny in range(y, y+size):
                    for nx in range(x, x+size):
                        if color != arr[ny][nx]:
                            flag = True
                            break
                    if flag:
                        break
                if not flag:
                    for _y in range(y, y+size):
                        for _x in range(x, x+size):
                            visited[_y][_x] = True
                    res[color] += 1
print(*res, sep='\n')

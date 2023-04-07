import sys
input = sys.stdin.readline

n, l = map(int, input().split())
dist, time = 0, 0
for _ in range(n):
    d, r, g = map(int, input().split())
    time += d - dist
    time += max(0, r - time % (r + g))
    dist = d

print(time + l - dist)

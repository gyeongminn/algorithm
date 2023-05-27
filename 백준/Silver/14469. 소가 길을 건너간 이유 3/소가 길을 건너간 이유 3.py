import sys
input = sys.stdin.readline

n = int(input())
arr = sorted([[int(x) for x in input().split()] for _ in range(n)])

time = 0
for s, t in arr:
    time += s - time if s > time else 0
    time += t
print(time)
from itertools import combinations
import sys
input = sys.stdin.readline

n = int(input())
arr = [int(x) for x in input().split()]
visited = [False] * (20 * 100000)

for i in range(1, n+1):
    for items in combinations(arr, i):
        visited[sum(items)] = True
for i in range(1, len(visited)):
    if not visited[i]:
        print(i)
        break
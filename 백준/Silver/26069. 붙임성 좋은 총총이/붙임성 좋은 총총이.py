from collections import defaultdict
import sys
input = sys.stdin.readline

dic = defaultdict(bool)
n = int(input())
for _ in range(n):
    a, b = input().split()
    if a == 'ChongChong' or b == 'ChongChong' or dic[a] or dic[b]:
        dic[a] = True
        dic[b] = True
    else:
        dic[a] = False
        dic[b] = False

cnt = 0
for i in dic:
    if dic[i]:
        cnt += 1
print(cnt)

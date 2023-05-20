import sys
input = sys.stdin.readline

s = set()
res = 0
n = int(input())
flag = False
for _ in range(n):
    a = input().rstrip()
    if a == 'ENTER':
        flag = True
        res += len(s)
        s = set()
        continue
    if a not in s:
        flag = False
        s.add(a)
res += len(s)
print(res)

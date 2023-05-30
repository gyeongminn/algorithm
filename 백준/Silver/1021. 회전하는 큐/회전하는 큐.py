import sys
from collections import deque

input = sys.stdin.readline
n, m = map(int, input().split())
dq = deque(range(1, n+1))
ans = 0
for target in map(int, input().split()):
    while True:
        if dq[0] == target:
            dq.popleft()
            break
        if dq.index(target) < len(dq) / 2:
            while dq[0] != target:
                dq.append(dq.popleft())
                ans += 1
        else:
            while dq[0] != target:
                dq.appendleft(dq.pop())
                ans += 1
print(ans)

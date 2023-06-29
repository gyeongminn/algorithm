import sys
from collections import deque
input = sys.stdin.readline


s = deque(input().rstrip())
t = deque(input().rstrip())

while len(t) != len(s):
    if t[-1] == 'A':
            t.pop()
    else:
        t.pop()
        t.reverse()

print(1 if s == t else 0)

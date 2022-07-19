from collections import deque
import sys

n = int(sys.stdin.readline())
dq = deque()

for _ in range(n):
    a = sys.stdin.readline().strip('\n').split()
    
    if a[0] == 'push_front':
        dq.appendleft(a[1])
        
    elif a[0] == 'push_back':
        dq.append(a[1])
        
    elif a[0] == 'pop_front':
        if len(dq) == 0:
            print(-1)
        else:
            print(dq.popleft())
            
    elif a[0] == 'pop_back':
        if len(dq) == 0:
            print(-1)
        else:
            print(dq.pop())
            
    elif a[0] == 'size':
        print(len(dq))
        
    elif a[0] == 'empty':
        if len(dq) == 0:
            print(1)
        else:
            print(0)
            
    elif a[0] == 'front':
        if len(dq) == 0:
            print(-1)
        else:
            d = dq.popleft()
            print(d)
            dq.appendleft(d)
        
    elif a[0] == 'back':
        if len(dq) == 0:
            print(-1)
        else:
            d = dq.pop()
            print(d)
            dq.append(d)
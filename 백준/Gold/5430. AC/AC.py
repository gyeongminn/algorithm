from collections import deque

for _ in range(int(input())):
    cmd = list(input())
    length = int(input())
    dq = deque(input()[1:-1].split(","))

    if length == 0:
        dq = deque()
    error = False
    reverse = 0

    for c in cmd:
        if c == 'R':
            reverse += 1
        if c == "D":
            if length == 0:
                error = True
                print("error")
                break
            if reverse % 2 == 1:
                dq.pop()
            else:
                dq.popleft()
            length -= 1

    if not error:
        if reverse % 2 == 1:
            dq.reverse()
        print("[" + ",".join(dq) + "]")

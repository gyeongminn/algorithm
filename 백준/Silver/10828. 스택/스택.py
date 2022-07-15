import sys

n = int(sys.stdin.readline())
s = []

for _ in range(n):
    i = sys.stdin.readline().split()

    if i[0] == 'push':
        s.append(int(i[1]))

    elif i[0] == 'pop':
        if len(s) == 0:
            print(-1)
        else:
            print(s.pop())

    elif i[0] == 'size':
        print(len(s))

    elif i[0] == 'empty':
        if len(s) == 0:
            print(1)
        else:
            print(0)

    elif i[0] == 'top':
        if len(s) == 0:
            print(-1)
        else:
            print(s[-1])
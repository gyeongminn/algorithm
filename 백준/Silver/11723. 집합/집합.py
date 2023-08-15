import sys
input = sys.stdin.readline

s = set()
n = int(input())

for _ in range(n):
    query = input().split()
    if query[0] == "all":
        s = set([i for i in range(1, 21)])
        continue
    elif query[0] == "empty":
        s = set()
        continue
    n = int(query[1])
    try:
        if query[0] == "add":
            s.add(n)
        elif query[0] == "remove":
            s.remove(n)
        elif query[0] == "check":
            print(1 if n in s else 0)
        elif query[0] == "toggle":
            if n in s:
                s.discard(n)
            else:
                s.add(n)
    except:
        pass
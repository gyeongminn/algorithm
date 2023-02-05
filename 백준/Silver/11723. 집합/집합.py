import sys
from collections import defaultdict

input = sys.stdin.readline

dic = defaultdict(bool)
empty = defaultdict(bool)
all = defaultdict(bool)
for i in range(1, 21):
    all[str(i)] = True

n = int(input())
for _ in range(n):
    query = input().split()
    if query[0] == "add":
        n = query[1]
        dic[n] = True
    elif query[0] == "remove":
        n = query[1]
        dic[n] = False
    elif query[0] == "check":
        n = query[1]
        if dic[n] == True:
            print(1)
        else:
            print(0)
    elif query[0] == "toggle":
        n = query[1]
        if dic[n] == True:
            dic[n] = False
        else:
            dic[n] = True
    elif query[0] == "all":
        dic = all
    elif query[0] == "empty":
        dic = empty

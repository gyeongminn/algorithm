import sys


n = int(sys.stdin.readline())
cards = list(map(int, sys.stdin.readline().split()))
m = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

hashmap = {}

for c in cards:
    hashmap[c] = 1

for a in arr:
    try:
        if hashmap[a] == 1:
            print(1, end=' ')
    except:
        print(0, end=' ')
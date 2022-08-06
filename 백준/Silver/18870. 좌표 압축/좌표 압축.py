import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
dic = {}

i = 0
for num in sorted(list(set(arr))):
    dic[num] = i
    i += 1

for num in arr:
    print(dic[num], end=' ')

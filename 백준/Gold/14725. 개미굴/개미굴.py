import sys
input = sys.stdin.readline

hash = set()
n = int(input())
for _ in range(n):
    k, *arr = input().split()
    for e in range(int(k)):
        tmp = arr[:e+1]
        hash.add("*".join(arr[:e+1]))
for item in sorted(hash):
    res = ''
    for i in range(item.count("*")):
        res += '--'
    print(res+item.split("*")[-1])

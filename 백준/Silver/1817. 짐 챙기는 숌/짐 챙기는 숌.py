import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [int(x) for x in input().split()]
ans = 0
pack = 0
for item in arr:
    pack += item
    if pack > m:
        pack = item
        ans += 1
    elif pack == m:
        pack = 0
        ans += 1
if pack:
    ans += 1    
print(ans)

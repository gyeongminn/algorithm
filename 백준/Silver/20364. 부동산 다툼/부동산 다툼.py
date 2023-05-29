import sys
input = sys.stdin.readline

n, q = map(int, input().split())
tree = [False] * (n+1)
for _ in range(q):
    a = b = int(input())
    ans = 0
    while a > 0:
        if tree[a]:
            ans = a
        a //= 2
    if not ans:
        tree[b] = True
    print(ans)

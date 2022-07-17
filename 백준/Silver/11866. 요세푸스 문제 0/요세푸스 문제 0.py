n, k = map(int, input().split())
arr = [i+1 for i in range(n)]

print('<', end='')
idx = 0
for i in range(n):
    idx += k - 1
    if idx >= len(arr):
        idx %= len(arr)
    print(arr.pop(idx), end='')
    if i != n - 1:
        print(', ', end='')
print('>')
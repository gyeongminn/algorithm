from collections import defaultdict

x = defaultdict(int)
y = defaultdict(int)

for _ in range(3):
    a, b = map(int, input().split())
    x[a] += 1
    y[b] += 1

print(sorted(x, key=lambda i: x[i])[0], sorted(y, key=lambda i: y[i])[0])

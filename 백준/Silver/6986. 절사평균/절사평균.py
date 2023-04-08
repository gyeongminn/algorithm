import sys
input = sys.stdin.readline


n, k = map(int, input().split())
data = sorted([float(input()) for _ in range(n)])

print('{:.2f}'.format(sum(data[k:n-k]) / (n-k*2) + 0.00000001))
print('{:.2f}'.format((sum(data[k:n-k]) + data[k]*k + data[n-k-1]*k) / n + 0.00000001))

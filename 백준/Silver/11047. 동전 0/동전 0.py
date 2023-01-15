n, k = map(int, input().split())
count = 0
coin = [0 for _ in range(n)]

for i in range(n) :
  coin[i] = int(input())

for i in reversed(range(n)) :
  count += (k // coin[i])
  k %= coin[i]

print(count)
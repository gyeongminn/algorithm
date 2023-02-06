from itertools import permutations

n = int(input())
arr = list(permutations(range(1, n+1), n))
for n in arr:
    print(*n)

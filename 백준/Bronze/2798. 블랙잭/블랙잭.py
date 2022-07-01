from itertools import combinations

n, m = map(int, input().split())
arr = list(map(int, input().split()))

combi_arr = list(combinations(arr, 3))
sum_arr = [sum(a) for a in combi_arr]

min = sum_arr[0]
for s in sum_arr:
    if m >= s:
        if abs(m - min) > abs(m - s):
            min = s
print(min)
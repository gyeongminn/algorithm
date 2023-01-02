from itertools import combinations

n = int(input())

distance_1 = [[] * x for x in range(n)]
distance_2 = [[] * x for x in range(n)]
count = [0 for _ in range(n)]

for i in range(n):
    arr = list(input())
    for j in range(n):
        if i == j:
            continue
        if arr[j] == 'Y':
            distance_1[i].append(j)

for i in range(n):
    for a, b in list(combinations(distance_1[i], 2)):
        if a not in distance_1[b]:
            distance_2[b].append(a)
        if b not in distance_1[a]:
            distance_2[a].append(b)

result = 0
for i in range(n):
    result = max(len(distance_1[i]) + len(set(distance_2[i])), result)
print(result)

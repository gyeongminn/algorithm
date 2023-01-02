from itertools import combinations

n = int(input())

arr = []
friends = [[] * x for x in range(n)]
friends2 = [[] * x for x in range(n)]
count = [0 for _ in range(n)]

for i in range(n):
    arr.append(list(input()))
    for j in range(n):
        if i == j:
            continue  # 자기자신은 패스
        if arr[i][j] == 'Y':
            friends[i].append(j)

for i in range(n):
    for a, b in list(combinations(friends[i], 2)):
        if a not in friends[b] and a not in friends2[b]:
            friends2[b].append(a)
        if b not in friends[a] and b not in friends2[a]:
            friends2[a].append(b)

result = 0
for i in range(n):
    result = max(len(friends[i]) + len(friends2[i]), result)
print(result)
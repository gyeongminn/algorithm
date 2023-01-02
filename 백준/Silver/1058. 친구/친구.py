n = int(input())
friends = [[] for _ in range(n)]

for i in range(n):
    tmp = list(input())
    for j in range(n):
        if tmp[j] == 'Y':
            friends[i].append(j)

max_friends = 0
for i in range(n):
    tmp = []
    for j in friends[i]:
        tmp += friends[j]
    max_friends = max(max_friends, len(set(tmp + friends[i])) - 1)
        
print(max_friends)
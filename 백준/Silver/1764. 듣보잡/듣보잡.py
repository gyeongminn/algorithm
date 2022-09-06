n, m = map(int, input().split())
dic = {}
arr = []

for _ in range(n):
    dic[input()] = 0
    
for _ in range(m):
    try:
        dic[input()] += 1
    except:
        pass

for s in list(dic.keys()):
    try:
        if dic[s] == 1:
            arr.append(s)
    except:
        pass
    
print(len(arr))
for name in sorted(arr):
    print(name)
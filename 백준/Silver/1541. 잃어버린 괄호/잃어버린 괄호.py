sub = input().split('-')
res = None
for item in sub:
    add = list(map(int, item.split('+')))
    if res == None:
        res = sum(add)
    else:
        res -= sum(add)
print(res)
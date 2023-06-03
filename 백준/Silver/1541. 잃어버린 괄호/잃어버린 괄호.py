sub = input().split('-')
ans = None
for item in sub:
    item = sum(map(int, item.split('+')))
    ans = item if ans == None else ans - item
print(ans)
a, c, e = map(int, input().split())
sa, sc, se = map(int, input().split())

if sa >= a and sc >= c and se >= e:
    print('A')
elif sa >= a/2 and sc >= c and se >= e:
    print('B')
elif sc >= c and se >= e:
    print('C')
elif sc >= c/2 and se >= e/2:
    print('D')
else:
    print('E')
case = 0
while True:
    l, p, v = map(int, input().split())
    if l == p == v == 0:
        break
    
    if v % p > l:
        result = v // p * l + l
    else:
        result = v // p * l + v % p
        
    case += 1
    print("Case %d: %d" %(case, result))
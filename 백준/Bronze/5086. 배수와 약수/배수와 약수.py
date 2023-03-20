while True:
    a, b= map(int, input().split())
    res = 'neither'
    if a and b:
        if not a % b:
            res = 'multiple'
        elif not b % a:
            res = 'factor'
    else:
        break
    print(res)
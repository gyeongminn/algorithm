while True:
    try:
        s = input().rstrip()
    except:
        break
    t = s
    while 'BUG' in t:
        r = t
        t = ''
        for item in r.split('BUG'):
            t += item
    print(t)
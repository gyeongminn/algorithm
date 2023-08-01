while True:
    s, a, b = input().split()
    if (s == '#' and a == b == '0'):
        break
    if int(a) > 17 or int(b) >= 80:
        r = 'Senior'
    else:
        r = 'Junior'
    print(s, r)
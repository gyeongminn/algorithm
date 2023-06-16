while True:
    s = input().rstrip()
    if s == 'END':
        break
    print(*list(reversed(s)), sep='')
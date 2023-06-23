check = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
while True:
    s = input().rstrip()
    if s == '#':
        break
    n = 0
    for c in s:
        if c in check:
            n += 1
    print(n)
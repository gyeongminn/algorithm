s = input().rstrip()
for c in s:
    if not ('a' <= c <= 'z' or 'A' <= c <= 'Z'):
        print(c, end='')
        continue
    a = ord(c) + 13
    if (c.isupper()):
        if a > ord('Z'):
            a -= 26
        print(chr(a), end='')
    else:
        if a > ord('z'):
            a -= 26
        print(chr(a), end='')
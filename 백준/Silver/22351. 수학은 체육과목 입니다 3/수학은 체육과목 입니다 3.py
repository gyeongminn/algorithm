a = input()
for l in range(1, len(a)+1):
    s = a[:l]
    n = int(s)
    while len(s) < len(a):
        n += 1
        s += str(n)
    if s == a:
        print(a[:l], n)
        exit(0)

for _ in range(int(input())):
    r, s = input().split()
    for c in list(s):
        for _ in range(int(r)):
            print(c, end='')
    print()
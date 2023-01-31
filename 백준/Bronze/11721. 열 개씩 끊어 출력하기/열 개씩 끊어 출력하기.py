s = list(input())

i = 0
for c in s:
    print(c, end='')
    i += 1
    if i > 9:
        i = 0
        print()
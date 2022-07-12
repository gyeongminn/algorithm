n = int(input())

for y in range(n):
    for x in range(n):
        if y % 2 == 0:
            print('* ', end='')
        else:
            print(' *', end='')
    print()
n = int(input())
if n == 1:
    print('*')
else:
    for y in range(n * 2):
        for x in range(n):
            if y % 2 == 0:
                if x % 2 == 0:
                    print('*', end='')
                else:
                    print(' ', end='')
            else:
                if x % 2 == 0:
                    print(' ', end='')
                else:
                    print('*', end='')
        print()
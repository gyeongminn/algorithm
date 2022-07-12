n = int(input())

for i in range(n - 1):
    print(' ' * (n - i - 1), end='')
    if i != 0: print('*', end='')
    print(' ' * (i * 2 - 1), end='')
    print('*')
print('*' * (2 * n - 1))
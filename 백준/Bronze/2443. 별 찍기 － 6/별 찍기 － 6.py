n = int(input())

for i in range(n-1, -1, -1):
    print(' ' * (n - i - 1), end='')
    print('*' * (i + 1), end='')
    print('*' * (i))
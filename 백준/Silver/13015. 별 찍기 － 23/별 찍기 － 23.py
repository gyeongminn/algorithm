n = int(input())

print('*' * n, end='')
print(' ' * (n * 2 - 3), end='')
print('*' * n)

for i in range(n - 2):
    print(' ' * (i + 1), end='')
    print('*', end='')
    print(' ' * (n - 2), end='')
    print('*', end='')
    print(' ' * ((n - 2 - i) * 2 - 1), end='')
    print('*', end='')
    print(' ' * (n - 2), end='')
    print('*')

print(' ' * (n - 1), end='')
print('*', end='')
print(' ' * (n - 2), end='')
print('*', end='')
print(' ' * (n - 2), end='')
print('*')

for i in range(n - 3, -1, -1):
    print(' ' * (i + 1), end='')
    print('*', end='')
    print(' ' * (n - 2), end='')
    print('*', end='')
    print(' ' * ((n - 2 - i) * 2 - 1), end='')
    print('*', end='')
    print(' ' * (n - 2), end='')
    print('*')

print('*' * n, end='')
print(' ' * (n * 2 - 3), end='')
print('*' * n)
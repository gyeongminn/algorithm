n = int(input())

for i in range(n):
    print(' ' * (n - i - 1), end='')
    for _ in range(i + 1):
        print('* ', end='')
    print()
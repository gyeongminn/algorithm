import sys
input = sys.stdin.readline


def sol(n):
    if n == 0:
        return '-'
    prev = sol(n-1)
    return prev + ' ' * pow(3, n-1) + prev


while True:
    try:
        print(sol(int(input())))
    except:
        break

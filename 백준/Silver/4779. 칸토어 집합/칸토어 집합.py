import sys
input = sys.stdin.readline


def sol(n):
    if n == 0:
        return '-'
    return sol(n-1) + ' ' * pow(3, n-1) + sol(n-1)
    
    
while True:
    try:
        n = int(input())
    except:
        break
    print(sol(n))

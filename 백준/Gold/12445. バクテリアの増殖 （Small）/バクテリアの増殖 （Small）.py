import sys
input = sys.stdin.readline

def solve():
    a, b, c = map(int, input().split())
    if b > 1:
        a = a ** a
    return pow(a, a, c)


if __name__ == '__main__':
    n = int(input())
    for i in range(n):
        print(f'Case #{i + 1}: {solve()}')
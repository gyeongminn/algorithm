import sys
from math import floor
input = sys.stdin.readline

n = int(input())
for _ in range(n):
    money = int(input())
    print(floor(money / 25), end=' ')
    money %= 25
    print(floor(money / 10), end=' ')
    money %= 10
    print(floor(money / 5), end=' ')
    money %= 5
    print(floor(money), end=' ')
    print()
import sys

input = sys.stdin.readline

zero = [0 for _ in range(41)]
one = [0 for _ in range(41)]

zero[0], zero[1] = 1, 0
one[0], one[1] = 0, 1

for i in range(2, 41):
    zero[i] = zero[i - 1] + zero[i - 2]
    one[i] = one[i - 1] + one[i - 2]

for _ in range(int(input())):
    n = int(input())
    print(zero[n], one[n])

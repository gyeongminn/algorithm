import sys

input = sys.stdin.readline
MAX = 1000000

divisor_sums = [0] * (MAX + 1)
prefix_sums = [0] * (MAX + 1)

for i in range(1, MAX + 1):
    for j in range(1, MAX // i + 1):
        divisor_sums[i * j] += i
    prefix_sums[i] = prefix_sums[i - 1] + divisor_sums[i]

for n in [int(input()) for _ in range(int(input()))]:
    print(prefix_sums[n])

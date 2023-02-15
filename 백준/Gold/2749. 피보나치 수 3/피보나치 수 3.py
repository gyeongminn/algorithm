import sys

input = sys.stdin.readline
mod = 1000000
p = mod // 10 * 15

n = int(input())

fibo = [0, 1]
for i in range(2, p):
    fibo.append((fibo[i-1] + fibo[i-2]) % mod)

print(fibo[n % p])

# 참고 : https://ii-eugene-ii.github.io/Post/Post01000/00130.html

import sys

input = sys.stdin.readline


def is_palin_prime(n):

    if n in [101101, 129921, 1837381]:
        return False

    if pow(2, n-1, n) == 1:
        return True
    else:
        return False


n, m = map(int, input().split())

result = 0

for i in [2, 3, 5, 7, 11]:
    if n <= i <= m:
        result += 1

start_digit = len(str(n))
if start_digit < 3:
    start_digit = 3
if start_digit % 2 == 0:
    start_digit + 1

end_digit = len(str(m))
if end_digit > 11:
    end_digit = 11

for digit in range(start_digit, end_digit + 1, 2):
    for mid_num in range(10):
        for j in range(1, pow(10, digit // 2), 2):
            half_num = str(j).zfill(digit // 2)
            num = int(half_num[::-1] + str(mid_num) + half_num)
            if not n <= num <= m or num % 10 == 5:
                continue
            if is_palin_prime(num):
                result += 1

print(result)

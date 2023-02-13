# 참고 : https://ii-eugene-ii.github.io/Post/Post01000/00130.html
# 참고 : https://ii-eugene-ii.github.io/Post/Post01000/00008.html
import sys

input = sys.stdin.readline
n, m = map(int, input().split())
result = 0

for i in [2, 3, 5, 7, 11]:
    if n <= i <= m:
        result += 1

if n <= 1837381 <= m:
    result -= 1

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
            if pow(2, num - 1, num) == 1:
                result += 1

print(result)

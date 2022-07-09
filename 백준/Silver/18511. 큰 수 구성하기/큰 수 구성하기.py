from itertools import product

n, m = map(int, input().split())
k = list(map(int, input().split()))
nums = list(product(k, repeat=len(str(n))))

len = len(str(n))
max = 0
while True:
    for num in nums:
        int_num = 0
        for i in range(len):
            int_num += num[i] * (10 ** i)
        if max < int_num <= n:
            max = int_num
    if max != 0:
        print(max)
        break
    len -= 1

a = input().rstrip()
b = input().rstrip()
cur = ''
for i in range(len(a)):
    cur += a[i] + b[i]
while len(cur) > 2:
    tmp = ''
    for i in range(len(cur)-1):
        tmp += str(int(cur[i]) + int(cur[i+1]))[-1]
    cur = tmp
print(cur)
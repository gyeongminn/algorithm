a, b = map(list, input().split())

a = list(reversed(a))
b = list(reversed(b))
a = a[0] + a[1] + a[2]
b = b[0] + b[1] + b[2]

if int(a) > int(b):
    print(int(a))
else:
    print(int(b))
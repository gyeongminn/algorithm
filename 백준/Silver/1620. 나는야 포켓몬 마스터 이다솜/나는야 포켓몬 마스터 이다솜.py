n, m = map(int, input().split())
number = {}
name = [""] * n

for i in range(n):
    str = input()
    number[str] = i + 1
    name[i] = str
    
for i in range(m):
    c = input()
    if c.isnumeric():
        print(name[int(c) - 1])
    else:
        print(number[c])
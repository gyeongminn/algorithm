a = int(input())
b = int(input())
if a > b:
    a, b = b, a
print(b+(b-a))
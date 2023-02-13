import math
for i, c in enumerate(list(reversed(str(math.factorial(int(input())))))):
    if c != '0':
        print(i)
        break
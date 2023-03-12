arr = list(input())
result = 0

for c in arr:
    if c <= 'C':
        result += 3
    elif c <= 'F':
        result += 4
    elif c <= 'I':
        result += 5
    elif c <= 'L':
        result += 6 
    elif c <= 'O':
        result += 7
    elif c <= 'S':
        result += 8 
    elif c <= 'V':
        result += 9 
    elif c <= 'Z':
        result += 10
        
print(result)
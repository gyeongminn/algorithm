def solution(arr):
    stack = []
    for c in arr:
        if c == '(' or c == '[':
            stack.append(c)
        if c == ')':
            if not stack:
                return False
            if stack.pop() != '(':
                return False
        if c == ']':
            if not stack:
                return False
            if stack.pop() != '[':
                return False
    if stack:
        return False
    else:
        return True
            
while True:
    arr = list(input())
    if len(arr) == 1 and arr[0] == '.':
        break
    if solution(arr):
        print("yes")
    else:
        print("no")

student = []

for _ in range(28):
    n = int(input())
    student.append(n)
    
for i in range(30):
    if i+1 not in student:
        print(i+1)
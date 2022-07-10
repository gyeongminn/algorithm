n = int(input())
member = [0] * n

for i in range(n):
    age, name = input().split()
    member[i] = [int(age), name]

member = sorted(member, key=lambda x: x[0])
for mem in member:
    print(mem[0], mem[1])
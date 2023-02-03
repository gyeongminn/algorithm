n = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
print(sum(map((lambda x, y:x*y), sorted(a), sorted(b, reverse=True))))
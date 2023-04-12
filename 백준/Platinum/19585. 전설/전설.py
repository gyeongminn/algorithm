import sys
input = sys.stdin.readline

c, n = map(int, input().split())

colors = set()
for _ in range(c):
    colors.add(input().rstrip())
    
names = set()
for _ in range(n):
    names.add(input().rstrip())

t = int(input())
for _ in range(t):
    team = input().rstrip()
    for i in range(1, min(len(team), 1001)):
        color, name = team[:i], team[i:]
        if color in colors and name in names:
            print("Yes")
            break
    else:
        print("No")

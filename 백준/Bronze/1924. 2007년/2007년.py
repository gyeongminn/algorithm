days = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]
x, y = map(int, input().split())
for m in range(1, x):
    if m in [1, 3, 5, 7, 8, 10, 12]:
        y += 31
    elif m in [4, 6, 9, 11]:
        y += 30
    else:
        y += 28
print(days[y % 7])
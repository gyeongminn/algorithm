from collections import defaultdict
import sys
input = sys.stdin.readline

dic = defaultdict(int)
n = int(input())
for _ in range(n):
    name, opt = input().split()
    if opt == 'enter':
        dic[name] = 1
    elif opt == 'leave':
        dic[name] = 0
        
for name, opt in sorted(dic.items(), reverse=True):
    if opt == 1:
        print(name)
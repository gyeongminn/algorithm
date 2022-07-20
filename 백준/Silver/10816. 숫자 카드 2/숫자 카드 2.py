import sys

n = int(sys.stdin.readline())
cards = list(map(int, sys.stdin.readline().split()))
m = int(sys.stdin.readline())
find = list(map(int, sys.stdin.readline().split()))
dic = {}

for card in cards + find:
    dic[card] = 0
    
for card in cards:
    dic[card] += 1
    
for i in range(m):
    print(dic[find[i]], end=' ')
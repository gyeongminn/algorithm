import sys
from collections import defaultdict

input = sys.stdin.readline
dic = defaultdict(int)

cnt_tree = 0
while True:
    tree = input().rstrip()
    if not tree:
        break
    dic[tree] += 1
    cnt_tree += 1

for tree in sorted(dic.keys()):
    result = dic[tree] / cnt_tree * 100
    print('%s %.4f' %(tree, result))

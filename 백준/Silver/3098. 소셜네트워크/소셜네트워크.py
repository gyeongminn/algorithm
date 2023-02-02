import sys
from collections import deque
input = sys.stdin.readline


def is_everyone_friend():
    count = 0
    for l in graph:
        if len(l) >= n:
            count += 1
            if count >= n:
                return True
    return False


n, m = map(int, input().split())
visited = [[False] * n for _ in range(n)]
graph = [[x] for x in range(n+1)]
answer = []

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

while True:  # 하루하루
    if is_everyone_friend():  # 모두 친구가 되었다면
        break  # 종료

    new_friends = []
    for person in range(1, n+1):
        for friend in graph[person]:  # 내 친구 탐색
            for friend_2 in graph[friend]:  # 내 친구의 친구 탐색
                if friend_2 not in graph[person]:  # 내 친구의 친구가 내 친구 목록에 없으면
                    new_friends.append([person, friend_2])  # 새로운 친구 목록에 추가

    count = 0  # 친구 등록 횟수
    for a, b in new_friends:
        if b not in graph[a]:  # 중복 제외
            graph[a].append(b)  # 서로서로 친구
            graph[b].append(a)  # 서로서로 친구
            count += 1
    answer.append(count)

print(len(answer), *answer, sep="\n")

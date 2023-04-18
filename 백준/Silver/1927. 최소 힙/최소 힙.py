import sys
import heapq
input = sys.stdin.readline

n = int(input())
heap = []
for _ in range(n):
    v = int(input())
    if not v:
        if not heap:
            print(0)
        else:
            print(heapq.heappop(heap))
    else:
        heapq.heappush(heap, v)
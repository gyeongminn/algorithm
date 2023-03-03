import sys
input = sys.stdin.readline
prime_numbers = [2, 3, 5, 7, 11, 13, 17]


def miller_rabin(n, check):
    if n == check:
        return True
    k = n - 1
    while True:
        x = pow(check, k, n)
        if x == n - 1:
            return True
        if k % 2 == 1:
            if x == 1:
                return True
            return False
        k //= 2


def is_prime(n):
    if n <= 1:
        return False
    for prime in prime_numbers:
        if not miller_rabin(n, prime):
            return False
    return True


def solution(arr):
    odd, even = [], []
    for num in arr:
        if num % 2:
            odd.append(num)
        else:
            even.append(num)
    if len(odd) != len(even):
        return False

    graph = [[] for _ in range(len(even)+1)]
    for i in range(1, len(even)+1):
        for j in range(1, len(odd)+1):
            if is_prime(even[i-1] + odd[j-1]):
                graph[i].append(j)
        if not graph[i]:
            return False

    def dfs(node):
        if visited[node]:
            return False
        visited[node] = True
        for next in graph[node]:
            if selected[next] == -1 or dfs(selected[next]):
                selected[next] = node
                return True
        return False

    selected = [-1] * (len(odd) + 1)
    for i in range(1, len(odd) + 1):
        visited = [False] * (len(odd) + 1)
        dfs(i)

    count = 0
    for i in range(1, len(odd)+1):
        if selected[i] >= 0:
            count += 1
    if count == len(odd):
        return True
    return False


n = int(input())
arr = [int(x) for x in input().split()]
result = []

for i in range(1, n):
    if is_prime(arr[0] + arr[i]):
        if solution(arr[1:i] + arr[i+1:]):
            result.append(arr[i])
if not result:
    print(-1)
else:
    print(*sorted(result))

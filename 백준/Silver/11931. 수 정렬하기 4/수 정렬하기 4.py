n = int(input())
arr = [int(input()) for _ in range(n)]
print(*sorted(arr, reverse=True), sep='\n')
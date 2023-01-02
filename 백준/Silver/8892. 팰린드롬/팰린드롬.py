from itertools import permutations


def is_palindrome(s: str):
    return list(s) == list(reversed(s))


def solution(arr: list):
    for i in list(permutations(arr, 2)):
        s = i[0] + i[1]
        if is_palindrome(s):
            return s
    return 0


t = int(input())

for _ in range(t):
    arr = []
    length = int(input())
    for _ in range(length):
        arr.append(input())
    print(solution(arr))

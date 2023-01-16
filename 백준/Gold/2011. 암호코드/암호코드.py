def solution(code):
    if code[0] == 0:
        return 0

    dp = [0 for _ in range(len(code) + 1)]
    dp[0], dp[1] = 1, 1

    for i in range(2, len(code) + 1):
        if code[i - 1] > 0:
            dp[i] += dp[i - 1] 
        if 10 <= code[i - 2] * 10 + code[i - 1] <= 26:
            dp[i] += dp[i - 2]
        dp[i] %= 1000000

    return dp[-1]


code = list(map(int, input()))
print(solution(code))

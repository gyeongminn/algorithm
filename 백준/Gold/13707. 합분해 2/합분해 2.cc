#include <bits/stdc++.h>
using namespace std;

#define MAX 5000
#define MOD 1'000'000'000

int dp[MAX + 1][MAX + 1];

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= MAX; i++) {
        dp[0][i] = 1; // n이 0이면 항상 1
        dp[i][1] = 1; // k가 1이면 항상 1
    }

    for (int i = 1; i <= MAX; i++) {
        for (int j = 2; j <= MAX; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
        }
    }

    cout << dp[n][k];
}

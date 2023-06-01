#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define endl '\n'
using namespace std;

int arr[100'000];
int dp[100'000];

int main(void) {
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    int ans = -100000;
    for (int i = 0; i < n; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}
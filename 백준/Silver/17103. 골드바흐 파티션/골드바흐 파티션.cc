#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<bool> sieve(int n) {
    vector<bool> state(n + 1, true);
    state[0] = state[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (!state[i])
            continue;
        for (int j = i * i; j <= n; j += i) {
            state[j] = false;
        }
    }
    return state;
}

int main(void) {
    fastio;
    vector<bool> prime = sieve(1000000);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int result = 0;
        for (int j = 2; j <= n / 2; j++) {
            if (prime[j] && prime[n - j]) {
                result += 1;
            }
        }
        cout << result << '\n';
    }
}
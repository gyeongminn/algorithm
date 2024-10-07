#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int answer = 1;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        answer += v - 1;
    }

    cout << answer;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
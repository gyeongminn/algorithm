#include <bits/stdc++.h>
using namespace std;

bool find(string s, string target) {
    for (int i = 0; i < s.length(); ++i) {
        int isMatched = true;
        for (int j = 0; j < target.length(); ++j) {
            if (s[(i + j) % s.length()] != target[j]) isMatched = false;
        }
        if (isMatched) return true;
    }
    return false;
}

void solve() {
    string target;
    cin >> target;

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        string ring;
        cin >> ring;
        ans += find(ring, target);
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
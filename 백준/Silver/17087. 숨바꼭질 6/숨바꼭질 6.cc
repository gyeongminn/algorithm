#include <bits/stdc++.h>
using namespace std;

int N, S;
vector<int> A;

void solve() {
    vector<int> v;
    for (auto i : A) {
        int k = abs(S - i);
        v.push_back(k);
    }

    int ans = v.front();
    for (auto i : v) {
        ans = gcd(ans, i);
    }

    cout << ans;
}

void input() {
    cin >> N >> S;
    A.resize(N);
    for (auto &i : A) {
        cin >> i;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}
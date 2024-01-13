#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, day, sum = 0;
    cin >> N;
    for (int i = 0; i < 6; ++i) {
        int v;
        cin >> v;
        sum += v;
    }
    for (day = 1; sum <= N; ++day) {
        sum *= 4;
    }
    cout << day << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
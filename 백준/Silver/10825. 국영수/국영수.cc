#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int, string>> v;

void solve() {
    sort(v.begin(), v.end());
    for (auto &[국어, 영어, 수학, 이름] : v) {
        cout << 이름 << '\n';
    }
}

void input() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string 이름;
        int 국어, 영어, 수학;
        cin >> 이름 >> 국어 >> 영어 >> 수학;
        v.emplace_back(-국어, 영어, -수학, 이름);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}
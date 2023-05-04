#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;

int ans[10];

void calc(int n, int idx) {
    while (n > 0) {
        ans[n % 10] += idx;
        n /= 10;
    }
}

void solve(int s, int e, int idx) {
    while (s % 10 != 0 && s <= e) {
        calc(s++, idx);
    }
    if (s > e) {
        return;
    }
    while (e % 10 != 9 && e >= s) {
        calc(e--, idx);
    }
    for (auto &i : ans) {
        i += (e / 10 - s / 10 + 1) * idx;
    }
    solve(s / 10, e / 10, idx * 10);
}

int main() {
    int n;
    cin >> n;
    solve(1, n, 1);
    for (auto i : ans) {
        cout << i << " ";
    }
}
#include <bits/stdc++.h>
using namespace std;

int N;
queue<int> q;

void solve() {
    int first = q.front();
    q.pop();

    while (!q.empty()) {
        int r = q.front();
        int g = gcd(first, r);
        q.pop();
        cout << first / g << '/' << r / g << '\n';
    }
}

void input() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        q.push(val);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

string a, b;

void solve() {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if (a.length() < b.length()) {
        swap(a, b);
    }
    int len_diff = a.length() - b.length();
    for (int i = 0; i < len_diff; ++i) {
        b += '0';
    }

    stack<int> s;
    bool round_up = false;
    for (int i = 0; i < a.length(); ++i) {
        int cur = a[i] + b[i] - '0' * 2 + round_up;
        round_up = false;

        if (cur > 1) {
            round_up = true;
            cur %= 2;
        }

        s.push(cur);
    }

    if (round_up) {
        s.push(1);
    }

    // Remove leading zero
    while (!s.empty() && s.top() == 0 && s.size() != 1) {
        s.pop();
    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

void input() {
    cin >> a >> b;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}
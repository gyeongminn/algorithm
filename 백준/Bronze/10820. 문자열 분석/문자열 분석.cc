#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    while (getline(cin, s)) {
        int a = 0, b = 0, d = 0, e = 0;

        for (char c : s) {
            if ('a' <= c && c <= 'z') {
                a++;
            } else if ('A' <= c && c <= 'Z') {
                b++;
            } else if ('0' <= c && c <= '9') {
                d++;
            } else if (c == ' ') {
                e++;
            }
        }

        cout << a << ' ' << b << ' ' << d << ' ' << e << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
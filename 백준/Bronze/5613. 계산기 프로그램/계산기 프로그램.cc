#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    while (true) {
        char o;
        cin >> o;

        if (o == '=') {
            cout << n;
            return;
        }

        int v;
        cin >> v;

        switch (o) {
            case '+':
                n += v;
                break;
            case '-':
                n -= v;
                break;
            case '*':
                n *= v;
                break;
            case '/':
                n /= v;
                break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
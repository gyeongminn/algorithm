#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    stack<int> s;
    while (n > 0) {
        s.push(n % 2);
        n /= 2;
    }

    int sum = 0;
    for (int i = 0; !s.empty(); ++i, s.pop()) {
        sum += s.top() * pow(2, i);
    }

    cout << sum;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
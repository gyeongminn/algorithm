#include <bits/stdc++.h>
using namespace std;

void solve() {
    int answer = 0, current = 0;
    for (int i = 0; i < 4; ++i) {
        int in, out;
        cin >> out >> in;
        current = current - out + in;
        answer = max(answer, current);
    }

    cout << answer;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
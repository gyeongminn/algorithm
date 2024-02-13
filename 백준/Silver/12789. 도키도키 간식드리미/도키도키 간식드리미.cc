#include <bits/stdc++.h>

using namespace std;

int N;
stack<int> s;

string solve() {
    int cur = 1;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (cur != a) {
            s.push(a);
        } else {
            cur++;
        }
        while (!s.empty() && cur == s.top()) {
            cur++;
            s.pop();
        }
    }

    return s.empty() ? "Nice" : "Sad";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    cout << solve();
    return 0;
}

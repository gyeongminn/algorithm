#include <bits/stdc++.h>
using namespace std;

void solve() {
    int first;
    cin >> first;

    vector<int> answer;
    for (int second = 0; second <= first; ++second) {
        int prev = first;
        int now = second;

        vector<int> current = {first, second};
        while (prev - now >= 0) {
            int next = prev - now;
            current.push_back(next);
            prev = now;
            now = next;
        }

        if (answer.size() < current.size()) {
            answer = current;
        }
    }

    cout << answer.size() << '\n';
    for (auto i : answer) cout << i << ' ';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
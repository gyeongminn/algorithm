#include <bits/stdc++.h>
using namespace std;

int N, M, J;

void solve() {
    int answer = 0;
    int left = 1, right = M;
    
    for (int i = 0; i < J; ++i) {
        int apple;
        cin >> apple;

        int diff = 0;
        if (left > apple) {
            diff = apple - left;
        } else if (apple > right) {
            diff = apple - right;
        }

        left += diff;
        right += diff;
        answer += abs(diff);
    }

    cout << answer;
}

void input() {
    cin >> N >> M >> J;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}
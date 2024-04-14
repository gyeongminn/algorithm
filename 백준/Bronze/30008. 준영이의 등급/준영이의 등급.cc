#ifdef LOCAL
#include <algo/debug.h>
#else
#define debug(...) 42
#endif

#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> A;

int tol[10] = {0, 4, 11, 23, 40, 60, 77, 89, 96, 100};

void solve() {
    for (const auto &s : A) {
        int r = s * 100 / N;
        for (int i = 1; i < 10; ++i) {
            if (r <= tol[i]) {
                cout << i << ' ';
                break;
            }
        }
    }
}

void input() {
    cin >> N >> K;
    A.resize(K);
    for (auto &i : A) cin >> i;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}
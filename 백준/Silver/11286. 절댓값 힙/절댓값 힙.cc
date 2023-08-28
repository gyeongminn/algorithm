#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

#define ll long long
#define endl '\n'
using namespace std;

ll N, X;
priority_queue<ll> pqp;
priority_queue<ll> pqn;

void solve() {
    cin >> X;
    if (X == 0) {
        if (pqp.empty() && pqn.empty()) {
            cout << 0 << endl;
            return;
        }
        if (pqn.empty() || (!pqp.empty() && abs(pqp.top()) < abs(pqn.top()))) {
            cout << -pqp.top() << endl;
            pqp.pop();
        } else {
            cout << pqn.top() << endl;
            pqn.pop();
        }
    } else if (X > 0) {
        pqp.emplace(-X);
    } else {
        pqn.emplace(X);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        solve();
    }
    return 0;
}
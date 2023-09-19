#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

ll N, F;

void solve() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            ll val = N - (N % 100) + 10 * i + j;
            if (val % F == 0) {
                cout << i << j;
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> F;
    solve();
    return 0;
}
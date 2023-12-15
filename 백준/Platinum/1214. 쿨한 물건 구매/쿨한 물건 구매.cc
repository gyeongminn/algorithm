#include <bits/stdc++.h>
using namespace std;

int D, P, Q;

int ceil_div(int a, int b) {
    return a / b + (a % b > 0);
}

int solve() {
    if (P < Q) swap(P, Q);  // P > Q
    if (D % P == 0 || D % Q == 0) return D;
    if (D <= Q) return Q;

    int ans = INT_MAX;
    for (int i = 0; i <= ceil_div(D, P) && i < Q; ++i) {
        int j = ceil_div(D - P * i, Q);
        if (j < 0) j = 0;
        int money = P * i + Q * j;
        if (money >= D) ans = min(ans, money);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> D >> P >> Q;
    cout << solve();
    return 0;
}
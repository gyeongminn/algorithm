#include <bits/stdc++.h>
using namespace std;

double H, W, N, M;

void solve() {
    long long r = ceil(H / (N + 1));
    long long c = ceil(W / (M + 1));
    cout << r * c;
}

void input() {
    cin >> H >> W >> N >> M;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}
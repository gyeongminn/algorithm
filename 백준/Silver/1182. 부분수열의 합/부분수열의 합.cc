#include <bits/stdc++.h>
using namespace std;

int N, S;
vector<int> v;
int ans;

void solve(int depth, int sum) {
    if (depth == N) {
        if (sum == S) ans++;
        return;
    }
    solve(depth + 1, sum + v[depth]);
    solve(depth + 1, sum);
}

void input() {
    cin >> N >> S;
    v.resize(N);
    for (auto &i : v) cin >> i;

    // S가 0인 경우, 공집합인 케이스를 제거해야 한다.
    if (S == 0) ans--; 
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve(0, 0);
    cout << ans;
    return 0;
}
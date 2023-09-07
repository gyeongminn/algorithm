#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

#define ll long long
#define endl '\n'
using namespace std;

int N;
int A[2048];
int DB[2048];

int solve() {
    fill(DB, DB + N, 1);

    for (int i = 1; i < N; ++i)
        for (int j = 0; j < i; ++j)
            if (A[j] > A[i])
                DB[i] = max(DB[i], DB[j] + 1);

    int ans = 0;
    for (int i = 0; i < N; ++i)
        ans = max(ans, DB[i]);

    return N - ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    cout << solve();
    return 0;
}
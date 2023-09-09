#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int N, K;
vector<int> v;
unordered_set<string> set_;

void solve() {
    sort(v.begin(), v.end());
    vector<int> tmp(N, 0);
    for (int i = 0; i < K; i++) tmp[i] = 1;
    do {
        string s;
        for (int i = 0; i < N; i++)
            if (tmp[i])
                s += to_string(v[i]);
        set_.insert(s);
    } while (next_permutation(v.begin(), v.end()));
    cout << set_.size();
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> K;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    solve();
    return 0;
}
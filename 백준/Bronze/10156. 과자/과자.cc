#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define endl '\n'
using namespace std;

int K, N, M;

int main() {
    fastio;
    cin >> K >> N >> M;
    int cash = K * N - M;
    cout << ((cash > 0) ? cash : 0);
    return 0;
}
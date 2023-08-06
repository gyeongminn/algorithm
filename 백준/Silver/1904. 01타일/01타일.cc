#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

#define ll long long
#define endl '\n'
using namespace std;

int db[1'000'001];

int solve(int n) {
    int mod = 15746;
    db[0] = db[1] = 1;
    db[2] = 2;
    for (int i = 2; i <= n; i++) {
        db[i] = (db[i - 1] + db[i - 2]) % mod;
    }
    return db[n];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
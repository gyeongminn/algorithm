#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll K, A, B, C, D;

string solve() {
    ll left = K * A + B;
    ll right = K * C + D;
    if (left == right) {
        return "Yes " + to_string(left);
    }
    return "No";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> K >> A >> B >> C >> D;
    cout << solve();
    return 0;
}
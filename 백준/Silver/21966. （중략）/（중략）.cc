#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

int N;
string S;

string solve() {
    if (N <= 25) return S;  // Case 1
    for (int i = 11; i < N - 12; ++i) {
        if (S[i] == '.') {
            return S.substr(0, 9) + "......" + S.substr(N - 10, 10); // Case 2
        }
    }
    return S.substr(0, 11) + "..." + S.substr(N - 11, 11);  // Case 3
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> N >> S;
    cout << solve();
    return 0;
}
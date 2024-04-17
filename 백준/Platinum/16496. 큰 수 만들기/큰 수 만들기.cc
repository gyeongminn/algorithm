#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

int N;
string A[1000];

int compare(string a, string b) {
    if (a + b > b + a) return 1;
    return 0;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A, A + N, compare);
    if (A[0] == "0") {
        cout << 0; return 0;
    }
    for (int i = 0; i < N; ++i) cout << A[i];
    return 0;
}
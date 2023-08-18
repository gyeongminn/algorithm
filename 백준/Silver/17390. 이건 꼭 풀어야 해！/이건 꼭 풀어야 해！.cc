#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int A[300'000];
int N, Q;

void solve() {
	sort(A, A + N + 1);
	for (int i = 1; i <= N; ++i) A[i] += A[i - 1];
	for (int i = 0; i < Q; ++i) {
		int l, r;
		cin >> l >> r;
		cout << A[r] - A[l - 1] << endl;
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> N >> Q;
	for (int i = 1; i <= N; ++i) cin >> A[i];
	solve();
	return 0;
}
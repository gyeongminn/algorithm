#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int T, N;
int A[1001];

int solve() {
	int ans = INT_MIN;
	for (int i = 1; i <= N; ++i) A[i] += A[i - 1];
	for (int i = 0; i <= N; ++i)
		for (int j = 0; j < i; ++j)
			ans = max(ans, A[i] - A[j]);
	return ans;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; ++i) cin >> A[i];
		cout << solve() << endl;
	}
	return 0;
}
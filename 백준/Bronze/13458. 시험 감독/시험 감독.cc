#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define endl '\n'
using namespace std;

int main() {
	fastio;
	int n, b, c;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	cin >> b >> c;

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		int a = max(0, v[i] - b);
		ans += a / c + ((a % c != 0) ? 1 : 0) + 1;
	}
	cout << ans;
	return 0;
}
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int N;
int A[100];
ll memo[1000][2];

ll dp(ll cur, ll num) {
	if (cur == N - 1) return 1;
	ll& ret = memo[cur][num];
	if (ret != -1) return ret;
	if (num == 1) return ret = dp(cur + 1, 0);
	return ret = dp(cur + 1, 0) + dp(cur + 1, 1);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> N;
	memset(memo, -1, sizeof(memo));
	cout << dp(0, 1);
	return 0;
}
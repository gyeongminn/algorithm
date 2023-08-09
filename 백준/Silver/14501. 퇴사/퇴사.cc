#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int N;
int D[1000];
int M[1000];
int memo[1000];

int dp(int day) {
	if (day > N) return INT_MIN;
	if (day == N) return 0;

	int& ret = memo[day];
	if (ret != -1) return ret;

	return ret = max(dp(day + 1), dp(day + D[day]) + M[day]);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	memset(memo, -1, sizeof(memo));
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> D[i]; cin >> M[i];
	}
	cout << dp(0);
    return 0;
}
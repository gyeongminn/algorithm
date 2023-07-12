#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int N, K;
int A[1100100];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];

	int ans = 0, cnt = 0;
	int e = 0;
	for (int s = 1; s <= N; ++s) {
		while (e + 1 <= N && cnt <= K) {
			if (cnt <= K) ans = max(ans, e - s + 1 - cnt);
			if (A[e + 1] % 2) cnt++;
			e++;
		}
		if (cnt <= K) ans = max(ans, e - s + 1 - cnt);
		if (A[s] % 2) cnt--;
	}

	cout << ans;
	return 0;
}
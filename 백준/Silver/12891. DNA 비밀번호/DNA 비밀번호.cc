#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int N, M;
char arr[1100100];
int check['Z'];
int cnt['Z'];
char dna[4] = {'A', 'C', 'G', 'T'};

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (char c : dna) cin >> check[c];

	for (int i = 0; i < M; i++) cnt[arr[i]]++;

	int ans = 0;
	for (int s = 0; s < N - M + 1; ++s) {
		int e = s + M - 1;
		bool flag = true;
		for (char c : dna) {
			if (check[c] > cnt[c]) {
				flag = false;
			}
		}
		if (flag) ans++;
		cnt[arr[s]]--;
		cnt[arr[e+1]]++;
	}
	cout << ans << endl;

	return 0;
}
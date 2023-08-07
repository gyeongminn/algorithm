#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int N;
int A[301];
int cache[301][3];

int calc(int x, int cnt) {
	if (x == N) return A[N];
	if (x > N) return -100000000;

	int &ret = cache[x][cnt];
	if (ret != -1) return ret;

	int one = (cnt < 2) ? calc(x + 1, cnt + 1) : -100000000;
	int two = calc(x + 2, 1);

	return ret = max(one, two) + A[x];
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	memset(cache, -1, sizeof(cache));

	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> A[i];

	cout << calc(0, 0);
	return 0;
}
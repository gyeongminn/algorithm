#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, x, y;
	cin >> n >> x >> y;
	int dx[4] = {0, 0, -1, 1};
	int dy[4] = {-1, 1, 0, 0};
	int cnt = 0;
	for (int i = 0; i < 4; ++i) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx < 1 || nx > n) continue;
		if (ny < 1 || ny > n) continue;
		cnt ++;
	}
	cout << cnt;
    return 0;
}
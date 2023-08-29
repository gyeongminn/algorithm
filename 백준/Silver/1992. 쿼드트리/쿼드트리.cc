#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

int N;
char A[64][64];

void solve(int r, int c, int size) {
	char val = A[r][c];
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			if (val != A[r + i][c + j])
				val = -1;
	if (val != -1) {
		cout << val;
		return;
	}
	cout << '(';
	size /= 2;
	solve(r, c, size);
	solve(r, c + size, size);
	solve(r + size, c, size);
	solve(r + size, c + size, size);
	cout << ')';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> A[i][j];
	solve(0, 0, N);
	return 0;
}
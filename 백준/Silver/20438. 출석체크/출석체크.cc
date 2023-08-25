#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int N, K, Q, M, S, E;
int A[5010]; // 졸고 있으면 1
int B[5010]; // 출석 코드를 못 받으면 1
int x;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	fill(B, B + 5003, 1);

	cin >> N >> K >> Q >> M;
	for (int i = 0; i < K; ++i) {
		cin >> x;
		A[x] = 1;
	}

	for (int i = 0; i < Q; ++i) {
		cin >> x;
		if (A[x]) continue; // 졸고 있는 경우
		for (int j = x; j < N + 3; j += x) // 배수 학생에게 코드 전달
			if (!A[j]) B[j] = 0; // 졸고 있으면 못 받음
	}

	for (int i = 3; i < N + 3; ++i) B[i] += B[i - 1]; // 누적 합

	for (int i = 0; i < M; ++i) {
		cin >> S >> E;
		cout << B[E] - B[S - 1] << endl;
	}
	return 0;
}
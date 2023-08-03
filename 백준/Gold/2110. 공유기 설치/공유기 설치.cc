#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int N, C;
int homes[200'000];
int MAX = 1'000'000'000;

// 결정 문제
// 모든 공유기의 간격이 gap 이상이 되는 방법이 있는지 반환
bool decision(int gap) {
	int limit = -1; // 설치할 수 있는 최소 위치
	int count = 0; // 설치 횟수
	for (int home : homes) {
		if (limit <= home) {
			count++;
			limit = home + gap; // 현재 집의 위치 + 거리
		}
	}
	return count >= C;
}

// 최적화 문제
// 최소 간격을 최대화한다
int optimize() {
	int lo = 0, hi = MAX;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (decision(mid)) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return hi;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> N >> C;
	for (int i = 0; i < N; ++i) cin >> homes[i];
	sort(homes, homes + N);
	cout << optimize();
	return 0;
}
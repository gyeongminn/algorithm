#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int N, M, K;
int A[100'001]; // 마을의 모래성의 개수
bool B[100'001]; // 돌이 굴러가기 시작하는 마을
priority_queue<pair<int, int>> pq; // Index, Value

void solve() {
	int sum = 0;
	for (int i = N; i >= 1; --i) { // 뒤에서부터
		sum += A[i]; // 누적합
		if (B[i]) { // 돌이 굴러가는 마을이면
			pq.emplace(sum, i); // PQ에 넣는다
			sum = 0; // 누적 합 초기화
		}
	}

	set<int> ans; // 정답 Set
	for (int i = 0; i < M; ++i) {
		ans.insert(pq.top().second); // Value가 가장 큰 Index를 뽑는다
		pq.pop();
	}
	
	for (auto i : ans) {
		cout << i << endl; // 출력
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i) cin >> A[i];
	for (int i = 1; i <= K; ++i) {
		int val;
		cin >> val;
		B[val] = true;
	}

	solve();
	return 0;
}
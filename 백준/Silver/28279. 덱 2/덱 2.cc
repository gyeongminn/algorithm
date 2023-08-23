#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

deque<int> dq;
int N;

void solve() {
	int opt, x;
	cin >> opt;
	switch (opt) {
		case 1: cin >> x;
			dq.push_front(x);
			break;
		case 2: cin >> x;
			dq.push_back(x);
			break;
		case 3:
			if (dq.empty()) {
				cout << -1 << endl;
				return;
			}
			cout << dq.front() << endl;
			dq.pop_front();
			break;
		case 4:
			if (dq.empty()) {
				cout << -1 << endl;
				return;
			}
			cout << dq.back() << endl;
			dq.pop_back();
			break;
		case 5: cout << dq.size() << endl;
			break;
		case 6: cout << ((dq.empty()) ? 1 : 0) << endl;
			break;
		case 7: cout << ((dq.empty()) ? -1 : dq.front()) << endl;
			break;
		default: cout << ((dq.empty()) ? -1 : dq.back()) << endl;
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; ++i) solve();
	return 0;
}
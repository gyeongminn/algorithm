#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int T;
stack<int> s;

void solve() {
	int opt, x;
	cin >> opt;
	switch (opt) {
		case 1: cin >> x;
			s.push(x);
			break;
		case 2:
			if (s.empty()) {
				cout << -1 << endl;;
			} else {
				cout << s.top() << endl;
				s.pop();
			}
			break;
		case 3: cout << s.size() << endl;;
			break;
		case 4: cout << ((s.empty()) ? 1 : 0) << endl;;
			break;
		default: cout << ((s.empty()) ? -1 : s.top()) << endl;
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> T;
	for (int i = 0; i < T; ++i) solve();
	return 0;
}
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	priority_queue<int, vector<int>, greater<int> > pq;
	int n, x;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		if (x) {
			pq.push(x);
		} else {
			if (pq.empty()) {
				cout << 0 << endl;
			} else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
	}
	return 0;
}
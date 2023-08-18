#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	stack<int> v;
	int n, num;
	string s;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		if (s == "push") {
			cin >> num;
			v.push(num);
		} else if (s == "pop") {
			if (v.empty()) {
				cout << -1 << endl;
			} else {
				cout << v.top() << endl;
				v.pop();
			}
		} else if (s == "size") {
			cout << v.size() << endl;
		} else if (s == "empty") {
			if (v.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		} else if (s == "top") {
			if (v.empty()) cout << -1 << endl;
			else cout << v.top() << endl;
		}
	}
	return 0;
}
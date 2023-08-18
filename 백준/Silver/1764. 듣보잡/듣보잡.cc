#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, ans = 0;
	string s;
	vector<string> v;
	map<string, bool> map;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		map[s] = true;
	}
	for (int i = 0; i < m; ++i) {
		cin >> s;
		if (map.find(s) != map.end()) {
			ans++;
			v.push_back(s);
		}
	}
	sort(v.begin(), v.end());
	cout << ans << endl;
	for (string name : v) {
		cout << name << endl;
	}
	return 0;
}
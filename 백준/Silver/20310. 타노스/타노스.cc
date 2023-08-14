#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;

	int cnt1 = 0;
	int cnt0 = 0;
	for (auto c : s) {
		if (c == '1') cnt1++;
		else cnt0++;
	}

	for (auto c : s) {
		if (c == '1') { // 뒤에 있는 1만 출력
			if (cnt1) cnt1 -= 2;
			else cout << '1';
		} else { // 앞에 있는 0만 출력
			if (cnt0) {
				cnt0 -= 2;
				cout << '0';
			}
		}
	}
	return 0;
}
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	string s[21] =
		{"1", "1", "2", "6", "24", "120", "720", "5040", "40320", "362880", "3628800", "39916800", "479001600"
		 , "6227020800", "87178291200", "1307674368000", "20922789888000", "355687428096000", "6402373705728000"
		 , "121645100408832000", "2432902008176640000"};
	cin >> n;
	cout << s[n];
	return 0;
}
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
    ll a, b;
	cin >> a >> b;
    cout << a * b / 2;
    return 0;
}   
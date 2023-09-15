#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t) cnt ++;
        else cnt--;
    }
    if (cnt < 0) cout << "Junhee is not cute!";
    else cout << "Junhee is cute!";
    return 0;
}
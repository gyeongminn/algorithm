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
    if (s[0] == '5' && s[1] == '5' && s[2] == '5') cout << "YES";
    else cout << "NO";
    return 0;
}
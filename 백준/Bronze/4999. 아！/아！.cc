#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define endl '\n'
using namespace std;

int main() {
    fastio;
    string a, b;
    cin >> a >> b;
    if (a.length() >= b.length()) cout << "go";
    else cout << "no";
    return 0;
}
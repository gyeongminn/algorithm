#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

char C;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> C;
    if (C == 'N' || C == 'n') {
        cout << "Naver D2";
    }
    else {
        cout << "Naver Whale";
    }
    return 0;
}
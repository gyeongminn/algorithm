#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

#define ll long long
#define endl '\n'
using namespace std;

int cache[21][21][21];

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
    int &ret = cache[a][b][c];
    if (ret != -1) return ret;
    if (a < b && b < c) return ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    return ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));
    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
    }
    return 0;
}
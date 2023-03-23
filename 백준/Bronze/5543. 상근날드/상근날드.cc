#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define endl '\n'

using namespace std;

int main(void) {
    fastio;
    int n, ans, min = 10000;
    for (int i = 0; i < 3; i++) {
        cin >> n;
        if (n < min) {
            min = n;
        }
    }
    ans = min;
    min = 10000;
    for (int i = 0; i < 2; i++) {
        cin >> n;
        if (n < min) {
            min = n;
        }
    }
    ans += min;
    cout << ans - 50;
}
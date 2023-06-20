#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(void) {
    fastio;
    int n, t, ans = 0;
    cin >> n;
    for (int i = 0; i < 5; i++) {
        cin >> t;
        if (n == t) {
            ans++;
        }
    }
    cout << ans;
}
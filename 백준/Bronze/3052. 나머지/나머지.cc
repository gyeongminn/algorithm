#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int cnt[42];

int main(void) {
    fastio;
    for (int i = 0; i < 10; i++) {
        int n;
        cin >> n;
        cnt[n % 42]++;
    }
    int ans = 0;
    for (int i = 0; i < 42; i++) {
        if (cnt[i]) {
            ans++;
        }
    }
    cout << ans;
}
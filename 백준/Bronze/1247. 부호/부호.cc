#ifdef LOCAL
#include <algo/debug.h>
#else
#define debug(...) 42
#endif

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    __int128 sum = 0;

    for (int i = 0; i < n; ++i) {
        long long k;
        cin >> k;
        sum += (__int128)k;
    }

    if (sum > 0) cout << "+\n";
    else if (sum < 0) cout << "-\n";
    else cout << "0\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 3;
    while (t--) solve();
    return 0;
}
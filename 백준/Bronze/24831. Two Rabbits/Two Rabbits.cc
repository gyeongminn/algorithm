#include <bits/stdc++.h>
using namespace std;

int solve() {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if ((y - x) % (a + b)) {
        return -1;
    } else {
        return (y - x) / (a + b);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

string solve() {
    string a, b;
    cin >> a >> b;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return (a == b) ? "Possible" : "Impossible";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}
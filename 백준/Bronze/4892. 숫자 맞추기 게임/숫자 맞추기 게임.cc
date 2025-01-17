#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    for (int i = 0;; i++) {
        int n;
        cin >> n;
        if (!n) return 0;

        string oddOrEven = (n & 1) ? ". odd " : ". even ";
        int n4 = (n * 3 + 1) / 2 * 3 / 9;

        cout << i + 1 << oddOrEven << n4 << '\n';
    }
}
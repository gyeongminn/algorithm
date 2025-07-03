#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    int pos = 1;
    while (n--) {
        int x, y;
        cin >> x >> y;
        if (pos == x) pos = y;
        else if (pos == y) pos = x;
    }

    cout << pos;
    return 0;
}
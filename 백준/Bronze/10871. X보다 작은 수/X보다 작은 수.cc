#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main(void) {
    fastio;
    int n, x, k;
    cin >> n >> x;
    for (int i = 0; i < n; i++ ) {
        cin >> k;
        if (k < x) cout << k << ' ';
    }
}
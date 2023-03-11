#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(void) {
    fastio;
    vector<bool> v(30, false);
    int n;
    for (int i = 0; i < 28; i++) {
        cin >> n;
        v[n - 1] = true;
    }
    for (int i = 0; i < 30; i++) {
        if (!v[i]) {
            cout << i + 1 << '\n';
        }
    }
}
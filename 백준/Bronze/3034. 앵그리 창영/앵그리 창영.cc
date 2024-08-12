#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, w, h;
    cin>> n >> w >> h;
    int max_seq = w * w + h * h;
    for(int i = 0; i < n; i++) {
        int len; cin >> len;
        if (len * len > max_seq) {
            cout << "NE\n";
        }else{
            cout << "DA\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
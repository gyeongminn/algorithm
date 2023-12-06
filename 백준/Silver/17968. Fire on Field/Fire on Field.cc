#include <bits/stdc++.h>
using namespace std;

int A[1001] = {1, 1,};

void solve() {
    for (int i = 2; i <= 1000; ++i) {
        for (int val = 1;; ++val) {
            bool flag = true;
            for (int k = 1; i - 2 * k >= 0; ++k) {
                if (val - A[i - k] == A[i - k] - A[i - 2 * k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                A[i] = val;
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    int n;
    cin >> n;
    cout << A[n];
    return 0;
}
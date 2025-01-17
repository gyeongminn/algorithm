#include <bits/stdc++.h>
using namespace std;

int check() {
    int r1, r2, r3, total;
    cin >> r1 >> r2 >> r3 >> total;

    for (int i = 0; i * r1 <= total; ++i) {
        for (int j = 0; i * r1 + j * r2 <= total; ++j) {
            for (int k = 0; i * r1 + j * r2 + k * r3 <= total; ++k) {
                if (i * r1 + j * r2 + k * r3 == total) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cout << check();
}
#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int factors[5000000];

int main(void) {
    fastio;

    for (int i = 0; i < 5000000; i++) {
        factors[i] = i;
    }

    for (int i = 2; i * i <= 5000000; i++) {
        if (factors[i] == i) {
            for (int j = i * i; j <= 5000000; j += i) {
                if (factors[j] == j) {
                    factors[j] = i;
                }
            }
        }
    }

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        while (n > 1) {
            cout << factors[n] << ' ';
            n /= factors[n];
        }
        cout << '\n';
    }
}
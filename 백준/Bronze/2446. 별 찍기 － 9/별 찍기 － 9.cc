#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main(void) {
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << ' ';
        }
        for (int j = 0; j < (n - i) * 2 - 1; j++) {
            cout << '*';
        }
        cout << '\n';
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << ' ';
        }
        for (int j = 0; j < (n - i) * 2 - 1; j++) {
            cout << '*';
        }
        cout << '\n';
    }
}
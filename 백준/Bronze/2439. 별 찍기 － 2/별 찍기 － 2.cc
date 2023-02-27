#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main(void) {
    fastio;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << ' ';
        }
        for (int j = 0; j < i; j++) {
            cout << '*';
        }
        cout << '\n';
    }
}
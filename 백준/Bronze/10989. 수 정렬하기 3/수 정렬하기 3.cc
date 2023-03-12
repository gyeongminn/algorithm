#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<int> v(10001, 0);

int main(void) {
    fastio;
    int n, t;
    cin >> n;
    while (n--) {
        cin >> t;
        v[t]++;
    }
    for (int i = 1; i < 10001; i++) {
        for (int j = 0; j < v[i]; j++) {
            cout << i << '\n';
        }
    }
}
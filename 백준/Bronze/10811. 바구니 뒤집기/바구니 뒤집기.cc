#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main(void) {
    fastio;
    int n, m, a, b;
    vector<int> v;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }
    while (m--) {
        cin >> a >> b;
        for (int i = 0; i <= (b - a) / 2; i++) {
            swap(v[a + i - 1], v[b - i - 1]);
        }
    }
    for (int i : v) {
        cout << i << ' ';
    }
}
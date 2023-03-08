#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main(void) {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(i + 1);
    }
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        swap(v[a - 1], v[b - 1]);
    }
    for (int i : v) {
        cout << i << ' ';
    }
}
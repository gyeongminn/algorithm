#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(void) {
    fastio;
    int a, b, c;
    vector<int> v(3);
    for (auto &i : v) {
        cin >> i;
    }
    sort(v.begin(), v.end());
    if (v[0] + v[1] <= v[2]) {
        cout << v[0] + v[1] + v[0] + v[1] - 1;
    } else {
        cout << v[0] + v[1] + v[2];
    }
}
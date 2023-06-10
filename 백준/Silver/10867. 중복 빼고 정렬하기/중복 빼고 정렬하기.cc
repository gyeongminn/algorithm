#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(void) {
    fastio;
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        s.insert(k);
    }
    for (auto it : s) {
        cout << it << ' ';
    }
}
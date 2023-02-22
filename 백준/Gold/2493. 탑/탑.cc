#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main(void) {
    fastio;
    int n, h;
    cin >> n;
    stack<pair<int, int>> s;
    s.push({0, numeric_limits<int>::max()});
    for (auto i = 1; i <= n; i++) {
        cin >> h;
        while (s.top().second < h)
            s.pop();
        cout << s.top().first << ' ';
        s.push({i, h});
    }
}
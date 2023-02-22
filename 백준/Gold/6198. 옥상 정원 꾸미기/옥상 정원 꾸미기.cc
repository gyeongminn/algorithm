#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define ll long long
using namespace std;

int main(void) {
    fastio;
    ll n, h, result = 0;
    cin >> n;
    stack<int> s;
    for (auto i = 0; i < n; i++) {
        cin >> h;
        while (!s.empty() && s.top() <= h)
            s.pop();
        result += s.size();
        s.push(h);
    }
    cout << result;
}
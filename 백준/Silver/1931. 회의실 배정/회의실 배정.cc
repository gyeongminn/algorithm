#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define endl '\n'
#define pstart second
#define pend first
using namespace std;

int main(void) {
    fastio;
    int t;
    cin >> t;
    vector<pair<int, int>> v(t);
    for (int i = 0; i < t; i++) {
        cin >> v[i].pstart >> v[i].pend;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int last = 0;
    for (int i = 0; i < t; i++) {
        if (last <= v[i].pstart) {
            last = v[i].pend;
            ans++;
        }
    }
    cout << ans;
}
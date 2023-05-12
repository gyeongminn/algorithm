#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

string solve() {
    int n, sum = 0;
    pair<int, int> m;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
        if (v[i] > m.first) {
            m.first = v[i];
            m.second = i;
        }
    }
    sort(all(v));
    if (upper_bound(all(v), m.first) - lower_bound(all(v), m.first) > 1) {
        return "no winner";
    }
    if (m.first > sum / 2) {
        return "majority winner " + to_string(m.second + 1);
    }
    return "minority winner " + to_string(m.second + 1);
}

int main(void) {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
}
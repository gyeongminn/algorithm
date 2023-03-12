#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

bool check(char c) {
    switch (c) {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        return false;
    default:
        return true;
    }
}

int main(void) {
    fastio;
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<char> res;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (res.size() == 0 && check(s[i])) {
            res.push_back(s[i]);
        } else if ((res.size() == 1 || res.size() == 2) && s[i] == 'A') {
            res.push_back(s[i]);
        } else if (res.size() > 2 && res.size() < m) {
            res.push_back(s[i]);
        }
    }

    if (res.size() != m) {
        cout << "NO";
    } else {
        cout << "YES\n";
        for (int i = m - 1; i >= 0; i--) {
            cout << res[i];
        }
    }
}

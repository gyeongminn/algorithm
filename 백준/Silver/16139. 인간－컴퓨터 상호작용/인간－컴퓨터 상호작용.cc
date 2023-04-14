#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;

int prefix[26][200100];

int main(void) {
    fastio;
    string s;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            prefix[s[i] - 'a'][j]++;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        char a;
        int l, r;
        cin >> a;
        cin >> l >> r;
        if (l == 0) {
            cout << prefix[a - 'a'][r] << endl;
        } else {
            cout << prefix[a - 'a'][r] - prefix[a - 'a'][l - 1] << endl;
        }
    }
}
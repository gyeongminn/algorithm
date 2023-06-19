#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(void) {
    fastio;
    string s;
    int c[26] = {0};
    cin >> s;
    for (auto it : s) {
        int idx = it - 'a';
        c[idx]++;
    }
    for (int i = 0; i < 26; i++) {
        cout << c[i] << ' ';
    }
}
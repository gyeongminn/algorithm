#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define endl '\n'
using namespace std;

int main(void) {
    fastio;
    ll s = 0;
    for (int i = 0; i < 4; i++) {
        int n;
        cin >> n;
        s += n;
    }
    cout << s / 60 << endl << s % 60;
}
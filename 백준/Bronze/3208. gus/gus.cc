#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define endl '\n'
using namespace std;

int main(void) {
    fastio;
    int a, b;
    cin >> a >> b;
    if (a > b) cout << 2 * (b-1) + 1 ;
    else cout << 2 * (a-1);
}
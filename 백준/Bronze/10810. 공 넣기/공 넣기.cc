#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main(void) {
    fastio;
    int n, m, a, b, c;
    cin >> n >> m;
    vector<int> basket(n, 0);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        for (int j = a; j <= b; j++) {
            basket[j - 1] = c;
        }
    }
    for (int &ball : basket) {
        cout << ball << ' ';
    }
}
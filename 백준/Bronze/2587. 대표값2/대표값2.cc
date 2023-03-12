#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main(void) {
    fastio;
    vector<int> v(5);
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());
    cout << sum / 5 << '\n' << v[2];
}
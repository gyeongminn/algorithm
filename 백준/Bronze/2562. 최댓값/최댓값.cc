#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main(void) {
    fastio;
    vector<int> v(9);
    for (int& n : v) {
        cin >> n;
    }

    cout << *max_element(v.begin(), v.end()) << '\n';
    cout << max_element(v.begin(), v.end()) - v.begin() + 1 << '\n';
}
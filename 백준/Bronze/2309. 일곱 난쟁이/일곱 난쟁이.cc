#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main(void) {
    fastio;
    vector<int> v(9);
    for (int& n : v) {
        cin >> n;
    }
    sort(v.begin(), v.end());

    int sum = accumulate(v.begin(), v.end(), 0);

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (v[i] + v[j] == sum - 100) {
                v.erase(v.begin() + j);
                v.erase(v.begin() + i - 1);
                goto endfor;
            }
        }
    }
endfor:

    for (int n : v) {
        cout << n << '\n';
    }
}
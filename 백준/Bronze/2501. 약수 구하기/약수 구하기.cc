#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main(void) {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<int> divisor;
    vector<int> tmp;

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divisor.push_back(i);
            int d = n / i;
            if (i != d)
                tmp.push_back(d);
        }
    }

    divisor.insert(divisor.end(), tmp.rbegin(), tmp.rend());

    if (divisor.size() < k) {
        cout << 0;
    } else {
        cout << divisor[k-1];
    }
}
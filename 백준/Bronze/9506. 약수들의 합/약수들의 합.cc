#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main(void) {
    fastio;
    while (true) {
        int n;
        cin >> n;
        if (n == -1)
            break;

        vector<int> divisor(1, 1);
        vector<int> tmp;

        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                divisor.push_back(i);
                int d = n / i;
                if (i != d)
                    tmp.push_back(d);
            }
        }

        divisor.insert(divisor.end(), tmp.rbegin(), tmp.rend());

        if (accumulate(divisor.begin(), divisor.end(), 0) == n) {
            cout << n << " = " << *divisor.begin();
            for (int i = 1; i < divisor.size(); i++) {
                cout << " + " << divisor[i];
            }
        } else {
            cout << n << " is NOT perfect.";
        }
        cout << '\n';
    }
}
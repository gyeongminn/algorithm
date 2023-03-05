#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main(void) {
    fastio;
    vector<bool> state(1000001, true);
    
    for (int i = 2; i * i <= 1000001; i++) {
        if (!state[i])
            continue;
        for (int j = i * i; j <= 1000001; j += i) {
            state[j] = false;
        }
    }

    while (true) {
        int n;
        cin >> n;
        if (!n)
            break;

        for (int i = 3; i < n; i += 2) {
            if (state[i] && state[n - i]) {
                cout << n << " = " << i << " + " << n - i << '\n';
                break;
            }
        }
    }
}
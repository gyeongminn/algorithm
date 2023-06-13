#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ull unsigned long long
#define endl '\n'
using namespace std;

ull fib[100];

int main(void) {
    fastio;
    fib[1] = 1;
    for (int i = 2; i < 100; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int t;
    cin >> t;
    while (t--) {
        stack<ull> st;
        ull n;
        cin >> n;
        while (n > 0) {
            ull a;
            for (int i = 0; i < 100; i++) {
                if (fib[i] <= n) {
                    a = fib[i];
                }
            }
            n -= a;
            st.push(a);
        }
        while (!st.empty()) {
            cout << st.top() << ' ';
            st.pop();
        }
        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int n = a + b;
    int m = a - b;
    if (n < m) swap(n, m);

    cout << n << endl << m;
    return 0;
}
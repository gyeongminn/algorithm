#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, v;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v;
        sum += v;
    }

    cout << (sum > 0 ? "1.00" : "divide by zero");
}
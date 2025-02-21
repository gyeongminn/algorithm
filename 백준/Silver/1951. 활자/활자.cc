#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;

    long long ans = 0;
    int numberOfDigits = log10(n) + 1;
    for (int i = 1; i < numberOfDigits; ++i) {
        ans += 9 * pow(10, i - 1) * i;
        ans %= 1234567;
    }

    ans += (n - pow(10, numberOfDigits - 1) + 1) * numberOfDigits;
    ans %= 1234567;

    cout << ans;
    return 0;
}
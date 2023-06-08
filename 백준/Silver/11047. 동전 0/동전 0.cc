#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    int coin[10];
    int n, k;
    cin >> n >> k;
    for (int i = n - 1; i >= 0; i--) {
        cin >> coin[i];
    }
    int ans = 0;
    for (int i = 0; k || i < n; ++i) {
        ans += k / coin[i];
        k %= coin[i];
    }
    cout << ans;
    return 0;
}

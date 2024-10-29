#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];

void solve() {
    int n;
    cin >> n;

    memset(arr, -1, sizeof(arr));

    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        int x, y, w, h;
        cin >> x >> y >> w >> h;

        for(int r = x; r < x + w; r++) {
            for(int c = y; c < y + h; c++) {
                int post = arr[r][c];
                if (post > -1) {
                    ans[post]--;
                }

                arr[r][c] = i;
                ans[i]++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
}


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}

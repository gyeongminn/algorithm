#include <bits/stdc++.h>
using namespace std;

string s;
int A[51]; // 역방향 누적합. '.'을 만나면 0으로 초기화

string solve() {
    string ans;
    int idx = 0;
    while (idx < s.length()) {
        if (A[idx] & 1) return "-1";
        if (A[idx] == 0) {
            ans += '.';
            idx++;
        } else {
            for (int i = 0; i < A[idx] / 4; ++i) {
                ans += "AAAA";
            }
            if (A[idx] % 4) ans += "BB";
            idx += A[idx];
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> s;
    for (int i = (int)s.length() - 1; i >= 0; i--) {
        A[i] = A[i + 1] + 1;
        if (s[i] == '.') A[i] = 0;
    }
    cout << solve();
    return 0;
}
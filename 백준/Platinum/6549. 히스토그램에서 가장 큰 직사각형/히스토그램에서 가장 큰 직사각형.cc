#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N;
vector<ll> A;

ll maxSquareAreaWithDilation(ll left, ll right, ll mid) {
    ll low = mid, high = mid + 1;
    ll height = min(A[low], A[high]);

    ll ret = height * 2;
    while (left < low || high < right) {
        if ((high < right) && (low == left || A[low - 1] < A[high + 1])) {
            height = min(height, A[++high]);
        } else {
            height = min(height, A[--low]);
        }
        ret = max(ret, height * (high - low + 1));
    }

    return ret;
}

ll solve(ll left, ll right) {
    if (left == right) return A[left];

    ll mid = (left + right) / 2;

    ll leftPart = solve(left, mid);
    ll rightPart = solve(mid + 1, right);
    ll midPart = maxSquareAreaWithDilation(left, right, mid);

    return max({leftPart, rightPart, midPart});
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    while (true) {
        cin >> N;
        if (!N) return 0;
        A.resize(N, 0);
        for (ll &i : A) cin >> i;
        cout << solve(0, N - 1) << '\n';
    }
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update> ordered_multi_set;

using ull = unsigned long long;

int N, K;
vector<int> v;
ordered_multi_set oms;

void erase(int value) {
    size_t index = oms.order_of_key(value);
    auto iter = oms.find_by_order(index);
    oms.erase(iter);
}

void solve() {
    ull ans = 0;
    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;

        v.push_back(t);
        oms.insert(t);

        if (i + 1 > K) {
            erase(v[i - K]);
        }

        if (i >= K - 1) {
            ans += *oms.find_by_order((K + 1) / 2 - 1);
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> K;
    solve();
    return 0;
}
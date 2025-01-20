#include <bits/stdc++.h>
using namespace std;

// https://gyeongmin.kr/p/pbds/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update> ordered_multi_set;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int &i : A) cin >> i;
    for (int &i : B) cin >> i;

    ordered_multi_set oms;
    for (int &i : B) {
        oms.insert(i);
    }

    int answer = 0;
    for (int &i : A) {
        // oms 내에서 i보다 작은 원소의 개수
        answer += oms.order_of_key(i);
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
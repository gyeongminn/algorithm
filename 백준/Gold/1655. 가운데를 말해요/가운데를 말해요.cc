#include <bits/stdc++.h>
using namespace std;

// https://gyeongmin.kr/p/pbds/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update> ordered_multi_set;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    int N, v;
    cin >> N;

    ordered_multi_set oms;
    for (int i = 0; i < N; ++i) {
        cin >> v;
        oms.insert(v);

        cout << *oms.find_by_order(i / 2) << '\n';
    }
    
    return 0;
}
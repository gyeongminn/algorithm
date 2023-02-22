#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main(void) {
    fastio;
    int n, k;
    cin >> n >> k;
    list<int> l;

    for (auto i = 0; i < n; i++) {
        l.push_back(i + 1);
    }
    cout << '<';
    auto it = l.begin();
    while (l.size() > 1) {
        for (auto i = 1; i < k; i++) {
            it++;
            if (it == l.end()) {
                it = l.begin();
            }
        }
        cout << *it << ", ";
        it = l.erase(it);
        if (it == l.end()) {
            it = l.begin();
        }
    }
    cout << *it << '>';
}
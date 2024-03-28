#include <bits/stdc++.h>
using namespace std;

struct Balloon {
  int index;
  int value;
};

deque<Balloon> dq;

void solve() {
    while (!dq.empty()) {
        Balloon b = dq.front();
        cout << b.index << ' ';

        dq.pop_front();
        for (int i = b.value > 0; i < abs(b.value); ++i) {
            if (b.value > 0) {
                dq.push_back(dq.front());
                dq.pop_front();
            } else {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
}

void input() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Balloon b = Balloon();
        b.index = i + 1;
        cin >> b.value;
        dq.push_back(b);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}
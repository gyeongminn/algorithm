#include <bits/stdc++.h>
using namespace std;

int A[10][10];

void grow() {
    for (auto &rows : A) {
        for (int &cell : rows) {
            cell++;
        }
    }
}

void solve() {
    bool visited[10][10];
    fill_n(&visited[0][0], 10 * 10, false);

    for (int j = 0; j < 6; ++j) {
        int n;
        cin >> n;
        int idx = n - 1;

        for (int i = 0; i < 10; ++i) {
            int r = j < 3 ? idx : i;
            int c = j < 3 ? i : idx;

            if (visited[r][c]) continue;

            A[r][c] = 1;
            visited[r][c] = true;
        }
    }
}

void print() {
    for (auto &rows : A) {
        for (int cell : rows) {
            cout << cell << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int k;
    cin >> k;

    grow();
    while (k--) {
        grow();
        solve();
    }
    print();

    return 0;
}
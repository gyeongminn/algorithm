#include <bits/stdc++.h>
using namespace std;

int N, M, L, R;
int A[101];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) A[i] = i;

    while (M--) {
        cin >> L >> R;
        for (int i = 0; i <= (R - L) / 2; ++i) {
            swap(A[L + i], A[R - i]);
        }
    }

    for (int i = 1; i <= N; ++i) cout << A[i] << ' ';
    return 0;
}
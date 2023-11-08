#include <bits/stdc++.h>
using namespace std;

int N;
int A[10'000];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < 2 * N; ++i) cin >> A[i];
    sort(A, A + 2 * N);

    int answer = INT_MAX;
    for (int i = 0; i < N; ++i) {
        answer = min(answer, A[i] + A[2 * N - i - 1]);
    }
    cout << answer;
    return 0;
}
// Lazy Propagation Fenwick Tree
// Reference: https://rebro.kr/94

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 300'000;
int N, M, L, R, x;
int arr[MAX];
int a_tr[MAX];  // 일차항 계수
int b_tr[MAX];  // 상수항

void update(int tr[], int i, int val) {
    while (i <= N) {
        tr[i] += val;
        i += (i & -i);
    }
}

int sum(const int tr[], int i) {
    int ans = 0;
    while (i > 0) {
        ans += tr[i];
        i -= (i & -i);
    }
    return ans;
}

void solve() {
    for (int i = 0; i < M; ++i) {
        cin >> L >> R >> x;
        update(a_tr, L, x);
        update(a_tr, R + 1, -x); //일차항 계수 update
        update(b_tr, L, (-L + 1) * x);
        update(b_tr, R + 1, R * x);
    }

    for (int i = 1; i <= N; ++i) {
        int res = 0;
        res += sum(a_tr, i) * i + sum(b_tr, i);  // [1 , R]
        res -= sum(a_tr, i - 1) * (i - 1) + sum(b_tr, i - 1);  // [1, L-1]
        cout << arr[i] + res << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> arr[i];
    solve();
    return 0;
}

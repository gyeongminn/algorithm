#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

#define ll long long
#define endl '\n'
using namespace std;

int N, M;
int A[100'000];

// 결정 문제
bool decision(int size) {
    int cnt = 0;
    int sum = 0;
    for (auto item: A) {
        if (sum + item > size) {
            cnt++;
            sum = 0;
        }
        sum += item;
    }
    if (sum != 0) cnt++;
//    cout << size << '\t' << cnt << endl;
    return cnt > M;
}

// 최적화 문제
int optimize(int min_val, int max_val) {
    int lo = min_val, hi = max_val;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
//        cout << lo << '\t' << mid << '\t' << hi << endl;
        if (decision(mid)) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int res = optimize(0, INT_MAX / 2);
    for (int i = 0; i < N; ++i) res = max(res, A[i]);
    cout << res;
    return 0;
}
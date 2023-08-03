#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

#define ll long long
#define endl '\n'
using namespace std;

int N, M;
int A[300'000];

// 결정 문제
bool decision(int d) {
    int sum = 0;
    for (auto item: A) {
        sum += (item / d) + ((item % d > 0) ? 1 : 0);
    }
    return sum > N;
}

// 최적화 문제
int optimize() {
    int lo = 1, hi = INT_MAX / 2;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
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
    for (int i = 0; i < M; ++i) cin >> A[i];
    sort(A, A + M);
    cout << optimize();
    return 0;
}
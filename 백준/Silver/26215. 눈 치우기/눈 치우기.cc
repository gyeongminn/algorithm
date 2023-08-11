#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

#define ll long long
#define endl '\n'
using namespace std;

int N;
int A[3000];

int solve() {
    priority_queue<int> pq;
    for (int i = 0; i < N; ++i) pq.push(A[i]);

    int time = 0;
    while (pq.size() > 1) {
        int val1 = pq.top(); // 가장 큰 값
        pq.pop();
        
        int val2 = pq.top(); // 두 번째로 큰 값
        pq.pop();

        time += val2; // val2만큼 눈을 치운다
        if (val1 - val2 > 0) pq.push(val1 - val2); // 남은 눈은 다시 넣는다
    }
    if (!pq.empty()) time += pq.top(); // 남은 눈을 마저 치운다

    if (time > 1440) time = -1;
    return time;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    cout << solve();
    return 0;
}
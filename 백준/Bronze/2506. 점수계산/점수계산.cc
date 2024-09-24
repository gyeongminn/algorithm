#include <bits/stdc++.h>
using namespace std;

int N, A[100];

void solve() {
    int weight = 1, answer = 0;
    
    for (int i = 0; i < N; ++i) {
        if (A[i] == 0) {
            weight = 1;
            continue;
        }
        
        answer += weight++;
    }
    cout << answer;
}

void input() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A;

int backtracking(int depth, int current, vector<bool> visited) {
    if (depth == N) {
        return 0;
    }
    
    visited[current] = true;

    int ret = 0;
    for (int next = 0; next < N; ++next) {
        if (visited[next] || current == next) continue;

        int term = abs(A[current] - A[next]);
        int value = term + backtracking(depth + 1, next, visited);
        ret = max(ret, value);
    }

    return ret;
}

void solve() {
    int answer = 0;
    for (int start = 0; start < N; ++start) {
        vector<bool> visited(N, false);
        
        int value = backtracking(0, start, visited);
        answer = max(answer, value);
    }

    cout << answer;
}

void input() {
    cin >> N;
    A.resize(N);
    for (int &i : A) cin >> i;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}
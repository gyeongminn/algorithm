#include <bits/stdc++.h>
using namespace std;

int N;
int dasom;
priority_queue<int> pq;

void solve() {
    int answer = 0;

    while (!pq.empty() && pq.top() >= dasom) {
        int max = pq.top();
        pq.pop();

        pq.push(max - 1);
        answer++;
        dasom++;
    }

    cout << answer;
}

void input() {
    cin >> N;
    cin >> dasom;
    for (int i = 0; i < N - 1; ++i) {
        int v;
        cin >> v;
        pq.push(v);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}
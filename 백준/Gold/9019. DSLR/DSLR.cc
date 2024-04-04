#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

int A, B;
bool visited[10000];

int D(int n) {
    return 2 * n % 10000;
}

int S(int n) {
    n -= 1;
    return (n >= 0) ? n : 9999;
}

int L(int n) {
    return (n * 10 + n / 1000) % 10000;
}

int R(int n) {
    return n % 10 * 1000 + n / 10;
}

void solve() {
    int next;
    queue<pair<int, string>> q;
    q.emplace(A, "");
    visited[A] = true;

    while (!q.empty()) {
        int cur = q.front().first;
        string s = q.front().second;
        q.pop();

        if (cur == B) {
            cout << s << '\n';
            return;
        }

        next = D(cur);
        if (!visited[next]) {
            visited[next] = true;
            q.emplace(next, s + 'D');
        }

        next = S(cur);
        if (!visited[next]) {
            visited[next] = true;
            q.emplace(next, s + 'S');
        }

        next = L(cur);
        if (!visited[next]) {
            visited[next] = true;
            q.emplace(next, s + 'L');
        }

        next = R(cur);
        if (!visited[next]) {
            visited[next] = true;
            q.emplace(next, s + 'R');
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        memset(visited, 0, sizeof(visited));
        cin >> A >> B;
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define endl '\n'
using namespace std;

int n, m;
int arr[10];
bool visited[10];

void solve(int depth) {
    if (depth == m) {
        for (int i = 1; i < m; ++i) {
            if (arr[i] < arr[i - 1]) {
                return;
            }
        }
        for (int i = 0; i < m; ++i) {
            cout << arr[i] << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            arr[depth] = i;
//            visited[i] = true;
            solve(depth + 1);
            visited[i] = false;
        }
    }
}

int main() {
    fastio;
    cin >> n >> m;
    solve(0);
}
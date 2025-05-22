#include <bits/stdc++.h>
using namespace std;

vector<int> abilities(8);

int solve(const vector<int> &indices) {
    for (int i = 0; i < 8; ++i) {
        int prev_idx = indices[(i + 7) % 8];
        int prev = abilities[prev_idx];

        int now_idx = indices[i];
        int now = abilities[now_idx];

        int next_idx = indices[(i + 1) % 8];
        int next = abilities[next_idx];

        long double harmonic_mean = (long double)prev * next / (prev + next);
        if ((long double)now <= sqrt(2) * harmonic_mean) return false;
    }

    return 1;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    for (int &x : abilities) cin >> x;

    vector<int> indices(8);
    for (int i = 0; i < 8; ++i) indices[i] = i;

    int answer = 0;
    do {
        answer += solve(indices);
    } while (next_permutation(indices.begin(), indices.end()));
    cout << answer;

    return 0;
}
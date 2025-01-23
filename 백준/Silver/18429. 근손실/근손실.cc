#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> KITS;
int answer;

bool check(const vector<int> &kits) {
    int weight = 500;
    for (int kit : kits) {
        weight = weight - K + kit;
        if (weight < 500) return false;
    }

    return true;
}

void permutation(vector<int> &data, int depth) {
    if (depth == N) {
        answer += check(data);
        return;
    }

    for (int next = depth; next < N; next++) {
        swap(data[depth], data[next]);
        permutation(data, depth + 1);
        swap(data[depth], data[next]);
    }
}

void input() {
    cin >> N >> K;
    KITS.resize(N);
    for (int &i : KITS) cin >> i;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();

    permutation(KITS, 0);
    cout << answer;
}
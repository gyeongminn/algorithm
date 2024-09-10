#include <bits/stdc++.h>
using namespace std;

vector<string> v;

int compare(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }

    int sum_a = 0, sum_b = 0;
    for (char c : a) {
        if ('0' <= c && c <= '9') {
            sum_a += c - '0';
        }
    }
    for (char c : b) {
        if ('0' <= c && c <= '9') {
            sum_b += c - '0';
        }
    }
    if (sum_a != sum_b) {
        return sum_a < sum_b;
    }

    return a < b;
}

void solve() {
    sort(v.begin(), v.end(), compare);
    for (auto i : v) cout << i << '\n';
}

void input() {
    int n;
    cin >> n;
    v.resize(n);
    for (auto &i : v)cin >> i;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<string> v;

int compare1(string a, string b) {
    if (a.size() != b.size())
        return a.size() > b.size();
    return a > b;
}

int compare2(string a, string b) {
    return a + b > b + a;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> K >> N;
    v.resize(K);
    for (auto &item: v) cin >> item;
    ranges::sort(v, compare1);
    for (int i = 0; i < N - K; i++) v.push_back(v[0]);
    ranges::sort(v, compare2);
    for (auto item: v) cout << item;
    return 0;
}
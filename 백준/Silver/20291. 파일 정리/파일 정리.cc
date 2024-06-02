#include <bits/stdc++.h>
using namespace std;

map<string, int> dic;

void solve() {
    for (auto item : dic) {
        cout << item.first << ' ' << item.second << endl;
    }
}

void input() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        string ext = s.substr(s.find('.') + 1);
        dic[ext]++;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}
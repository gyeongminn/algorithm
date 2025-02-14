#include <bits/stdc++.h>
using namespace std;

int calc(const string &team, const string &yeondu) {
    vector<int> cnt('Z' + 1, 0);
    for (char c : team) cnt[c]++;
    for (char c : yeondu) cnt[c]++;

    return ((cnt['L'] + cnt['O'])
        * (cnt['L'] + cnt['V'])
        * (cnt['L'] + cnt['E'])
        * (cnt['O'] + cnt['V'])
        * (cnt['O'] + cnt['E'])
        * (cnt['V'] + cnt['E'])) % 100;
}

struct compare {
  bool operator()(const pair<int, string> &a, const pair<int, string> &b) {
      if (a.first != b.first) return a.first < b.first;
      else return a.second > b.second;
  }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string yeondu;
    cin >> yeondu;

    int n;
    cin >> n;

    priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;

    while (n--) {
        string team;
        cin >> team;
        pq.push({calc(team, yeondu), team});
    }

    cout << pq.top().second;

    return 0;
}
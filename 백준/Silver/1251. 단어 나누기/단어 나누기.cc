#include <bits/stdc++.h>
using namespace std;

string solve(string s) {
    string minStr = "";
    for (int i = 1; i < s.size() - 1; ++i) {
        for (int j = i + 1; j < s.size(); ++j) {
            string l = s.substr(0, i);
            string m = s.substr(i, j - i);
            string r = s.substr(j);

            reverse(l.begin(), l.end());
            reverse(m.begin(), m.end());
            reverse(r.begin(),r.end());

            string newStr = l + m + r;
            if (minStr.size() == 0 || minStr > newStr) minStr = newStr;
        }
    }

    return minStr;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string s;
    cin >> s;
    cout << solve(s);
    return 0;
}
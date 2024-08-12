#include <bits/stdc++.h>
using namespace std;

set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

void solve() {
    while (true) {
        string s; cin >> s;
        if (s == "end") return;

        bool isValid = false;

        // rule 1
        for (char c : s) {
            if (vowels.contains(c)) isValid = true;
        }

        // rule 2
        int nVowels = 0, nConsonants = 0;
        for (int i = 0; i < s.length(); i++) {
            if (vowels.contains(s[i])) {
                nConsonants = 0;
                nVowels++;
            } else {
                nVowels = 0;
                nConsonants++;
            }

            if (nVowels > 2 || nConsonants > 2) {
                isValid = false;
            }
        }

        // rule 3
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i + 1] && s[i] != 'e' && s[i] != 'o') {
                isValid = false;
            }
        }

        cout << "<" << s << "> is " << (isValid ? "" : "not ") << "acceptable." << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
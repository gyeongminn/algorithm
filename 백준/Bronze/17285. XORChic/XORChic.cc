#include <bits/stdc++.h>
using namespace std;

string chic(string s, int key) {
    for (auto &c : s) c = (char)((int) c ^ key);
    return s;
}

int findKey(const string& s) {
    for (int key = 0; key < 100; ++key) {
        string tmp = chic(s, key);
        bool flag = true;
        for (int i = 0; i < 7; ++i) {
            if (tmp[i] != "CHICKEN"[i]) flag = false;
        }
        if (flag) return key;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string s;
    cin >> s;
    int key = findKey(s);
    cout << chic(s, key);
    return 0;
}
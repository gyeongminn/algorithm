#include <bits/stdc++.h>
using namespace std;

int main() {
    int seq = 0;
    string target = "UCPC";
    while (!cin.eof()) {
        char c;
        cin >> c;
        if (c == target[seq]) {
            seq++;
        }
    }

    cout << "I " << (seq == 4 ? "love" : "hate") << " UCPC";
}
#include <bits/stdc++.h>
using namespace std;

string rock, king;

string getNext(string coord, int columnOffset, int rowOffset) {
    return string(1, coord[0] + columnOffset) + string(1, coord[1] + rowOffset);
}

bool isInRange(string coord) {
    if (coord[0] < 'A' || coord[0] > 'H' || coord[1] < '1' || coord[1] > '8') return false;
    return true;
}

void solve() {
    string cmd;
    cin >> cmd;

    int columnOffset = 0, rowOffset = 0;
    if (cmd.find('T') != string::npos) rowOffset++;
    if (cmd.find('B') != string::npos) rowOffset--;
    if (cmd.find('L') != string::npos) columnOffset--;
    if (cmd.find('R') != string::npos) columnOffset++;

    string nextKing = getNext(king, columnOffset, rowOffset);
    if (!isInRange(nextKing)) return;

    if (nextKing == rock) {
        string nextRock = getNext(rock, columnOffset, rowOffset);
        if (!isInRange(nextRock)) return;
        rock = nextRock;
    }

    king = nextKing;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    int n;
    cin >> king >> rock;
    cin >> n;
    while (n--) {
        solve();
    }
    cout << king << '\n' << rock;

    return 0;
}
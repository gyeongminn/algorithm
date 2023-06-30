#include <bits/stdc++.h>

using namespace std;


bool dig(int r, int c) {
    if (r < 0 || r > 9 || c < 0 || c > 9) return false;
    cout << "? " << r << " " << c << endl;
    int found;
    cin >> found;
    return found == 1;
}

void dig_near(int r, int c) {
    if (dig(r - 1, c)) {
        cout << "! " << r - 1 << " " << c << " " << r << " " << c << endl;
        exit(0);
    }
    if (dig(r, c - 1)) {
        cout << "! " << r << " " << c - 1 << " " << r << " " << c << endl;
        exit(0);
    }
    if (dig(r + 1, c)) {
        cout << "! " << r + 1 << " " << c << " " << r << " " << c << endl;
        exit(0);
    }
    cout << "! " << r << " " << c + 1 << " " << r << " " << c << endl;
    exit(0);
}

int main() {
    for (int r = 1; r < 9; r++) {
        for (int c = 1; c < 9; c++) {
            if (r % 2 != c % 2) continue;
            if (dig(r, c)) {
                dig_near(r, c);
            }
        }
    }
    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            if (r == 0 && c == 0) continue;
            if (r == 9 && c == 9) continue;
            if (r % 2 != c % 2) continue;
            if (r == 0 || r == 9 || c == 0 || c == 9) {
                if (dig(r, c)) {
                    dig_near(r, c);
                }
            }
        }
    }
    if (dig(0, 0)) {
        dig_near(0, 0);
    }
    if (dig(9, 8)) {
        cout << "! 9 9 9 8" << endl;
        exit(0);
    }
    cout << "! 9 9 8 9" << endl;
}

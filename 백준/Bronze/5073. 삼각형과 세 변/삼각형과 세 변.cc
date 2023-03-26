#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(void) {
    fastio;
    int a, b, c;
    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) {
            break;
        } else if (max({a, b, c}) >= a + b + c - max({a, b, c})) {
            cout << "Invalid\n";
        } else if (a == b && b == c) {
            cout << "Equilateral\n";
        } else if (a == b || b == c || c == a) {
            cout << "Isosceles\n";
        } else {
            cout << "Scalene\n";
        }
    }
}
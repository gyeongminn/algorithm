#include <bits/stdc++.h>
using namespace std;

int reverse_num(int num) {
    for (int i = 0; i < 3; i++) {
        num = num % 10 * 100 + num % 100 / 10 * 10 + num / 100;
    }
    return num;
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    if (reverse_num(n1) > reverse_num(n2))
        cout << reverse_num(n1);
    else
        cout << reverse_num(n2);
}
#include <bits/stdc++.h>
using namespace std;

int A, P;
vector<int> D;

int findNext(int n) {
    int sum = 0;
    for (int i = n; i >= 1; i /= 10) {
        int eachNumber = i % 10;
        sum += pow(eachNumber, P);
    }

    return sum;
}

void solve() {
    D.push_back(A);

    int n = A;
    while (true) {
        n = findNext(n);

        for (int i = 0; i < D.size(); ++i) {
            if (D[i] == n) {
                cout << i;
                return;
            }
        }

        D.push_back(n);
    }
}

void input() {
    cin >> A >> P;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}
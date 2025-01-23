#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, C;
    double G;
    cin >> N;

    int sumOfC = 0;
    double gpa = 0;
    for (int i = 0; i < N; ++i) {
        cin >> C >> G;
        sumOfC += C;
        gpa += C * G;
    }

    gpa /= sumOfC;

    cout << sumOfC << ' ' << gpa << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
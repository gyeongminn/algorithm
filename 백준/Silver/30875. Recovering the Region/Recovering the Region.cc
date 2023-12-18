#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
	int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << i + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}
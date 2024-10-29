#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int want_to_drink = 0;
    int answer = 0;
    
    for(int i = 0; i < n; i++) {
        int v; 
        cin >> v;
        
        if (want_to_drink == v) {
            want_to_drink = (want_to_drink + 1) % 3;
            answer++;
        }
    }
    
    cout << answer;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}

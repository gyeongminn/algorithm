#include <bits/stdc++.h>
using namespace std;

int compare(string a, string b) {
    if(a + b > b + a) return 1;
    else return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end(), compare);
    if(v[0]=="0") cout << "0";
    else {for (int i = 0; i < n; ++i) cout << v[i];}
    return 0;
}
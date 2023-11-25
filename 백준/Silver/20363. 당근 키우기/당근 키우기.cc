#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int X, Y;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> X >> Y;
    cout << X + Y + min(X, Y) / 10;
    return 0;
}

// 0 ≤ X, Y ≤ 10^9 이므로 O(N^2) 풀이는 불가능. -> DP or Greedy 풀이가 필요함.
// 연속해서 주던, 번갈아가며 주던 결과는 같고, 적어도 X + Y 번 물을 줘야 함.
// 0에 도달하면 감소되지 않으므로, X, Y 중 큰 것 먼저 주는것이 항상 최적해를 가짐.

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string solve() {
    string s;
    cin >> s;

    // 내림차순 정렬인 경우, BIGGEST (len = 1 인 경우도 해당됨)
    if (is_sorted(s.begin(), s.end(), greater<>())) return "BIGGEST";

    for (int i = s.size() - 2; i >= 0; --i) {
        if (s[i] < s[i + 1]) { // 자신보다 우측 수가 더 큰 경우 찾기
            for (int j = s.size() - 1; j > i; --j) { // s[i]의 오른쪽 탐색
                if (s[i] < s[j]) { // s[i]의 오른쪽 부분 중, 자신보다 우측 수가 더 큰 경우 찾기
                    swap(s[i], s[j]); // s[i]와 s[j]를 교환
                    sort(s.begin() + i + 1, s.end()); // 나머지 뒷부분을 정렬
                    return s;
                }
            }
        }
    }

    return "";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
    return 0;
}
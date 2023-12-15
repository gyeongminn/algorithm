#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<>> pq;  // 강의의 끝나는 지점을 저장, 최소힙
vector<pair<int, int>> v;  // 강의 저장

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; ++i) cin >> v[i].first >> v[i].second;
    
    sort(v.begin(), v.end());  // 시작시간-끝시간 정렬

    for (auto [start, end] : v) {
        pq.push(end);
        // 마지막 강의의 끝나는 시간 <= 새 강의의 시작 시간
        if (pq.top() <= start) pq.pop();
    }
    cout << pq.size();

    return 0;
}
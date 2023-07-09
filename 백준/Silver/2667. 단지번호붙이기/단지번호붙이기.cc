#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define endl '\n'
using namespace std;

typedef struct point {
  int r, c;
} point;

int N;
constexpr int MAX = 200;
char graph[MAX][MAX];
bool visited[MAX][MAX];
point dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(point start) {
	visited[start.r][start.c] = true;
	queue<point> q;
	q.push(start);
	int cnt = 1;
	while (!q.empty()) {
		point cur = q.front();
		q.pop();
		for (point dir : dirs) {
			point next = {cur.r + dir.r, cur.c + dir.c};
			if (next.r < 0 || next.r >= N || next.c < 0 || next.c >= N)
				continue;
			if (!visited[next.r][next.c] && graph[next.r][next.c] == '1') {
				visited[next.r][next.c] = true;
				q.push(next);
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	fastio;
	cin >> N;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			cin >> graph[r][c];
		}
	}
	vector<int> ans;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			if (!visited[r][c] && graph[r][c] == '1') {
				ans.push_back(bfs({r, c}));
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i << endl;
	}
	return 0;
}
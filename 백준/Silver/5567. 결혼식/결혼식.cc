#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<set<int>> friends;
vector<bool> visited;

struct node {
  int person, distance;
};

int solve() {
    queue<node> queue;
    queue.push({1, 0});
    visited[queue.front().person] = true;

    int count = 0;

    while (!queue.empty()) {
        node current_node = queue.front();
        queue.pop();

        if (current_node.distance > 1) continue;

        for (int person : friends[current_node.person]) {
            node next_node = {person, current_node.distance + 1};
            if (visited[next_node.person]) continue;

            visited[next_node.person] = true;
            queue.push(next_node);
            count++;
        }
    }

    return count;
}

void input() {
    cin >> N >> M;
    friends.resize(N + 1);
    visited.resize(N + 1);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        friends[a].insert(b);
        friends[b].insert(a);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    cout << solve();
    return 0;
}
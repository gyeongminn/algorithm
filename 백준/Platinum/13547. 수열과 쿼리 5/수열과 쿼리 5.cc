#include <bits/stdc++.h>
using namespace std;

typedef struct query {
    int index, start, end;
} query;

int N, M;
vector<int> arr;
vector<int> frequency;
vector<query> queries;
vector<int> answers;

void solve() {
    int block_size = max(1, static_cast<int>(sqrt(N)));
    answers.resize(M);

    ranges::sort(queries, [&](const query &a, const query &b) {
        int block_a = a.start / block_size;
        int block_b = b.start / block_size;
        if (block_a != block_b) return block_a < block_b;
        if (!(block_a & 1)) return a.end < b.end;
        return a.end > b.end;
    });

    int current_left = 0;
    int current_right = -1;
    int distinct_count = 0;

    auto add_value = [&](const int value) {
        if (frequency[value] == 0) distinct_count++;
        frequency[value]++;
    };

    auto remove_value = [&](const int value) {
        frequency[value]--;
        if (frequency[value] == 0) distinct_count--;
    };

    for (const query &q: queries) {
        while (current_left > q.start) add_value(arr[--current_left]);
        while (current_right < q.end) add_value(arr[++current_right]);
        while (current_left < q.start) remove_value(arr[current_left++]);
        while (current_right > q.end) remove_value(arr[current_right--]);

        answers[q.index] = distinct_count;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    frequency.resize(1'000'000 + 1);

    cin >> N;
    arr.resize(N);
    for (int &i: arr) cin >> i;

    cin >> M;
    for (int index = 0; index < M; index++) {
        int i, j;
        cin >> i >> j;
        queries.push_back({index, i - 1, j - 1});
    }

    solve();
    for (int answer: answers) cout << answer << "\n";

    return 0;
}
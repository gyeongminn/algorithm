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
    int exactly_twice_count = 0;

    auto add_value = [&](const int value) {
        int before = frequency[value];
        if (before == 1) exactly_twice_count++;
        else if (before == 2) exactly_twice_count--;
        frequency[value] = before + 1;
    };

    auto remove_value = [&](const int value) {
        int before = frequency[value];
        if (before == 2) exactly_twice_count--;
        else if (before == 3) exactly_twice_count++;
        frequency[value] = before - 1;
    };

    for (const query &q: queries) {
        while (current_left > q.start) add_value(arr[--current_left]);
        while (current_right < q.end) add_value(arr[++current_right]);
        while (current_left < q.start) remove_value(arr[current_left++]);
        while (current_right > q.end) remove_value(arr[current_right--]);

        answers[q.index] = exactly_twice_count;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> N >> M;
    arr.resize(N);
    for (int &i: arr) cin >> i;

    vector<int> values = arr;
    ranges::sort(values);
    values.erase(ranges::unique(values).begin(), values.end());
    for (int &x: arr) {
        x = static_cast<int>(ranges::lower_bound(values, x) - values.begin());
    }
    frequency.assign(static_cast<int>(values.size()), 0);

    queries.reserve(M);
    for (int index = 0; index < M; index++) {
        int i, j;
        cin >> i >> j;
        queries.push_back({index, i - 1, j - 1});
    }

    solve();
    for (int answer: answers) cout << answer << "\n";
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_SIZE = 300'000;
constexpr int MAX_COLOR = 10'000;
constexpr int SECTION_COUNT = 548; // >= sqrt(300,000)
constexpr int SECTION_SIZE = SECTION_COUNT; // fixed 548

int N, C;
int colors[MAX_SIZE];

int section_candidate_color[SECTION_COUNT];
int section_candidate_count[SECTION_COUNT];

vector<int> color_positions[MAX_COLOR + 1];

int count_color_in_range(int color, int start_index, int end_index) {
    const vector<int>& positions = color_positions[color];
    auto left_it = lower_bound(positions.begin(), positions.end(), start_index);
    auto right_it = upper_bound(positions.begin(), positions.end(), end_index);
    return static_cast<int>(right_it - left_it);
}

void merge_candidate(int incoming_color, int incoming_count, int& merged_color, int& merged_count) {
    if (incoming_count == 0) return;

    if (merged_count == 0) {
        merged_color = incoming_color;
        merged_count = incoming_count;
        return;
    }

    if (merged_color == incoming_color) {
        merged_count += incoming_count;
        return;
    }

    if (merged_count > incoming_count) {
        merged_count -= incoming_count;
        return;
    }

    if (incoming_count > merged_count) {
        merged_color = incoming_color;
        merged_count = incoming_count - merged_count;
        return;
    }

    merged_color = 0;
    merged_count = 0;
}

void find_majority_candidate_in_range(int start_index, int end_index, int& candidate_color, int& candidate_count) {
    candidate_color = 0;
    candidate_count = 0;

    for (int index = start_index; index <= end_index; index++) {
        int color = colors[index];

        if (candidate_count == 0) {
            candidate_color = color;
            candidate_count = 1;
        }
        else if (candidate_color == color) {
            candidate_count++;
        }
        else {
            candidate_count--;
        }
    }
}

void prepare() {
    fill_n(section_candidate_color, SECTION_COUNT, 0);
    fill_n(section_candidate_count, SECTION_COUNT, 0);

    for (int section_index = 0; section_index < SECTION_COUNT; section_index++) {
        int start_index_of_section = section_index * SECTION_SIZE;
        if (start_index_of_section >= N) break;

        int end_index_of_section = min(start_index_of_section + SECTION_SIZE - 1, N - 1);

        int candidate_color = 0;
        int candidate_count = 0;
        find_majority_candidate_in_range(start_index_of_section, end_index_of_section, candidate_color, candidate_count);

        section_candidate_color[section_index] = candidate_color;
        section_candidate_count[section_index] = candidate_count;
    }
}

void query(int start_index, int end_index) {
    int length = end_index - start_index + 1;

    int start_section = (start_index + SECTION_SIZE - 1) / SECTION_SIZE;
    int end_section = (end_index / SECTION_SIZE) - 1;

    int final_candidate_color = 0;
    int final_candidate_count = 0;

    if (start_section > end_section) {
        find_majority_candidate_in_range(start_index, end_index, final_candidate_color, final_candidate_count);
    } else {
        int left_end_index = start_section * SECTION_SIZE - 1;

        int right_start_index = (end_section + 1) * SECTION_SIZE;

        if (start_index <= left_end_index) {
            int left_candidate_color = 0;
            int left_candidate_count = 0;
            find_majority_candidate_in_range(start_index, left_end_index, left_candidate_color, left_candidate_count);
            merge_candidate(left_candidate_color, left_candidate_count, final_candidate_color, final_candidate_count);
        }

        int inside_candidate_color = 0;
        int inside_candidate_count = 0;
        for (int section_index = start_section; section_index <= end_section; section_index++) {
            int section_color = section_candidate_color[section_index];
            int section_count = section_candidate_count[section_index];
            merge_candidate(section_color, section_count, inside_candidate_color, inside_candidate_count);
        }
        merge_candidate(inside_candidate_color, inside_candidate_count, final_candidate_color, final_candidate_count);

        if (right_start_index <= end_index) {
            int right_candidate_color = 0;
            int right_candidate_count = 0;
            find_majority_candidate_in_range(right_start_index, end_index, right_candidate_color, right_candidate_count);
            merge_candidate(right_candidate_color, right_candidate_count, final_candidate_color, final_candidate_count);
        }
    }

    if (final_candidate_color == 0) {
        cout << "no\n";
        return;
    }

    int frequency = count_color_in_range(final_candidate_color, start_index, end_index);
    if (frequency > length / 2) {
        cout << "yes " << final_candidate_color << "\n";
    } else {
        cout << "no\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> C;

    for (int index = 0; index < N; index++) {
        cin >> colors[index];
        color_positions[colors[index]].push_back(index);
    }

    prepare();

    int M;
    cin >> M;
    for (int query_index = 0; query_index < M; query_index++) {
        int A, B;
        cin >> A >> B;
        query(A - 1, B - 1); // zero-based index
    }

    return 0;
}
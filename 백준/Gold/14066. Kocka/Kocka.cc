#include <bits/stdc++.h>
using namespace std;
const int block_height = 4;
const int block_width = 5;
const int MAX = 500;
string block[6] = {"+---+", "/   /|", "+---+ |", "|   | +", "|   |/", "+---+"};
char board[MAX][MAX];

int n_depth, n_col;
vector<vector<int>> v;
int max_height;

void draw(int r, int c) {
//    assert(r >= 0);
//    assert(c >= 0);
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < block[i].size(); ++j) {
            int start = 0;
            if (i == 0) start = 2;
            if (i == 1) start = 1;
            board[r + i][c + j + start] = block[i][j];
        }
    }
}

void make() {
    for (int depth = 0; depth < v.size(); ++depth) {
        int max_depth = (int)v[depth].size();
        for (int column = 0; column < max_depth; ++column) {
            int height = v[depth][column];
            for (int i = 0; i < height; ++i) {
                int row = (max_height - 1 - i + depth) * (block_height - 1) - depth;
                int col = (max_depth + column - depth) * (block_width - 1) + depth * 2;
                draw(row, col);
            }
        }
    }
}

void show(int start_r, int end_r, int start_c, int end_c) {
    for (int r = start_r; r < end_r; ++r) {
        for (int c = start_c; c < end_c + 1; ++c) {
            cout << board[r][c];
        }
        cout << '\n';
    }

//    for (int i = 0; i < 30; ++i) {
//        for (int j = 0; j < 30; ++j) {
//            cout << board[i][j];
//        }
//        cout << '\n';
//    }
}

void input() {
    cin >> n_depth >> n_col;
    v.resize(n_depth);
    for (auto &row : v) {
        row.resize(n_col);
        for (auto &item : row) {
            cin >> item;
            max_height = max(max_height, item);
        }
    }
}

void solve() {
    fill_n(&board[0][0], sizeof(board), '.');
    make();

    int start_r = 0, end_r = INT_MAX, start_c = 0, end_c = INT_MAX;

    for (int i = 0; i < MAX; ++i) {
        bool flag = true;
        for (int j = 0; j < MAX; ++j) {
            if (board[i][j] != '.') {
                flag = false;
                break;
            }
        }
        if (flag) {
            start_r = max(start_r, i + 1);
        } else {
            break;
        }
    }

    for (int i = MAX - 1; i >= 0; --i) {
        bool flag = true;
        for (int j = 0; j < MAX; ++j) {
            if (board[i][j] != '.') {
                flag = false;
                break;
            }
        }
        if (flag) {
            end_r = min(end_r, i);
        } else {
            break;
        }
    }

    for (int i = 0; i < MAX; ++i) {
        bool flag = true;
        for (int j = 0; j < MAX; ++j) {
            if (board[j][i] != '.') {
                flag = false;
                break;
            }
        }
        if (flag) {
            start_c = max(start_c, i + 1);
        } else {
            break;
        }
    }

    for (int i = MAX - 1; i >= 0; --i) {
        bool flag = true;
        for (int j = 0; j < MAX; ++j) {
            if (board[j][i] != '.') {
                flag = false;
                break;
            }
        }
        if (flag) {
            end_c = min(end_c, i - 1);
        } else {
            break;
        }
    }

    show(start_r, end_r, start_c, end_c);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}
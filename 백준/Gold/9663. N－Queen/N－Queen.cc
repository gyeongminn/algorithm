#include <bits/stdc++.h>
using namespace std;

int N, answer;

// board 배열은 (1, 2) 좌표를 board[1]=2 와 같이 저장
bool check(int row, int column, vector<int> &board) {
    for (int r = 0; r < row; ++r) {
        if (board[r] == column) return false;
        int row_offset = row - r, column_offset = column - board[r];
        if (row_offset == abs(column_offset)) return false;
    }
    return true;
}

void solve(int row, vector<int> &board) {
    if (row == N) {
        answer++;
        return;
    }

    for (int column = 0; column < N; ++column) {
        if (!check(row, column, board)) continue;
        board[row] = column;
        solve(row + 1, board);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> N;
    vector<int> board(N + 1);
    solve(0, board);
    cout << answer;

    return 0;
}
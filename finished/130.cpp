#include <cstdio>
#include <queue>
#include <vector>

#include "dbg.h"

using namespace std;

void bfs(vector<vector<char>>& b, int row, int col) {
    b[row][col] = 'A';
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++) {
        int nr = row + dx[i];
        int nc = col + dy[i];
        if (nr >= 0 && nr < b.size() && nc >= 0 && nc < b[0].size() &&
            b[nr][nc] == 'O') {
            bfs(b, nr, nc);
        }
    }
}

void solve(vector<vector<char>>& board) {
    if (board.empty()) return;
    int row = board.size();
    int col = board[0].size();
    if (col == 0) return;

    // traverse 4 edges
    for (int i = 0; i < col; i++) {
        if (board[0][i] == 'O') {
            bfs(board, 0, i);
        }

        if (board[row - 1][i] == 'O') {
            bfs(board, row - 1, i);
        }
    }

    for (int j = 1; j < row - 1; j++) {
        if (board[j][0] == 'O') {
            bfs(board, j, 0);
        }
        if (board[j][col - 1] == 'O') {
            bfs(board, j, col - 1);
        }
    }
    dbg(board);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == 'O') board[i][i] = 'X';
            if (board[i][j] == 'A') board[i][i] = 'O';
        }
    }
    dbg(board);
}

int main() {
    vector<vector<char>> v{{'O', 'X', 'X'}, {'O', 'O', 'X'}, {'X', 'X', 'O'}};
    solve(v);
    return 0;
}
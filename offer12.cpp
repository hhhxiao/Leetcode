#include <string>
#include <vector>
using namespace std;

bool search(vector<vector<char>> &board, int r, int c, const string &word,
            int idx, vector<vector<int>> &flags) {
    if (idx == word.size()) return true;
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() ||
        board[r][c] != word[idx]) {
        return false;
    }
    if (flags[r][c] == 0) {
        flags[r][c] = 1;
        static int dx[4] = {0, 0, 1, -1};
        static int dy[4] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + r;
            int ny = dy[i] + c;
            if (search(board, nx, ny, word, idx + 1, flags)) {
                return true;
            }
        }

        flags[r][c] = 0;
    }
    return false;
}
bool exist(vector<vector<char>> &board, string word) {
    int row = board.size();
    int col = board[0].size();
    std::vector<std::vector<int>> flags(row, std::vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == word[0]) {
                if (search(board, i, j, word, 0, flags)) {
                    return true;
                }
            }
        }
    }
    return false;
}

// sudoku solver
#include <vector>

#include "dbg.h"
#include "io/io.h"

using namespace std;

vector<vector<char>> res;

std::vector<char> getCandidate(int r, int c, const vector<vector<char>>& b) {
    bool arr[10]{false};
    for (int i = 0; i < 9; i++) {
        if (b[i][c] != '.') {
            // printf("1. rm %c\n", b[i][c]);
            arr[b[i][c] - '0'] = true;
        }
        if (b[r][i] != '.') {
            // printf("2. rm %c\n", b[r][i]);
            arr[b[r][i] - '0'] = true;
        }
    }

    int bx = r / 3;
    int by = c / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (b[bx * 3 + i][by * 3 + j] != '.') {
                // printf("3. rm %c\n", b[bx + i][by + j]);
                arr[b[bx * 3 + i][by * 3 + j] - '0'] = true;
            }
        }
    }
    std::vector<char> cans;
    for (int i = 1; i <= 9; i++) {
        if (!arr[i]) {
            cans.push_back(i + '0');
        }
    }
    return cans;
}

bool solve(vector<vector<char>>& b) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (b[i][j] == '.') {
                auto c = getCandidate(i, j, b);
                for (auto x : c) {
                    b[i][j] = x;
                    if (solve(b)) {
                        res = b;
                        return true;
                    }
                    b[i][j] = '.';
                }
                return false;
            }
        }
    }
    res = b;
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    solve(board);
    board = res;
    for (auto d : res) {
        dbg(d);
    }
}

int main() {
    auto sd = read_matrix<char>("input.txt", 9, 9);
    for (auto d : sd) {
        dbg(d);
    }
    solveSudoku(sd);
    return 0;
}
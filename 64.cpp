#include <vector>

#include "dbg.h"

using namespace std;

int min(int x, int y) { return x < y ? x : y; }

int minPathSum(vector<vector<int>>& grid) {
    auto row = grid.size();
    auto col = grid[0].size();
    auto idx_min = min(row, col);
    for (int i = 1; i < col; i++) {
        grid[0][i] += grid[0][i - 1];
    }

    for (int i = 1; i < row; i++) {
        grid[i][0] += grid[i - 1][0];
    }

    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
    }

    // for (int i = 1; i < idx_min; i++) {

    //     for (int j = i; j < row; j++) {
    //         grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
    //     }
    //     for (int j = i + 1; j < col; j++) {
    //         grid[j][i] += min(grid[j - 1][i], grid[j][i - 1]);
    //     }
    // }

    return grid[row - 1][col - 1];
}
/*
1 2 3
4 5 6
 */
int main(int argc, char const* argv[]) {
    // std::vector<std::vector<int>> v = {{1, 2, 3}, {4, 5, 6}};
    // dbg(v);
    // dbg(minPathSum(v));
    // dbg(v);
    std::clog << "QAQ";
    return 0;
}

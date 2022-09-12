#include <algorithm>
#include <vector>

#include "dbg.h"

using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int row = grid.size();
    int col = grid[0].size();
    std::vector<int> row_max;  //每行最大值
    std::vector<int> col_max;  //每列最大值
    for (int i = 0; i < row; i++) {
        row_max.push_back(*std::max_element(grid[i].begin(), grid[i].end()));
    }

    for (int i = 0; i < col; i++) {
        int m = grid[0][i];
        for (int j = 1; j < row; j++) {
            if (m < grid[j][i]) m = grid[j][i];
        }
        col_max.push_back(m);
    }

    dbg(row_max, col_max);

    int res = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res += std::min(row_max[i], col_max[j]) - grid[i][j];
        }
    }
    return res;
}

int main() {
    vector<vector<int>> v{
        {3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}};
    dbg(maxIncreaseKeepingSkyline(v));
    return 0;
}

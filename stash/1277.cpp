#include <stdio.h>

#include <algorithm>
#include <cstdio>
#include <locale>
#include <numeric>
#include <type_traits>

#include "a.h"

using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    std::vector<std::vector<pair<int, int>>> table;

    int r = matrix.size();
    int c = matrix[0].size();
    table.push_back({});
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] == 1) {
                table[0].emplace_back(i, j);
            }
        }
    }
    // dbg(table.back());

    int max = std::min(r, c);
    for (int i = 2; i <= max; i++) {
        table.push_back({});
        auto& p = table[i - 2];
        for (auto& pos : p) {
            // 检查右下方i+1个点是否都是1
            int row = pos.first + i - 1;
            int col = pos.second + i - 1;

            if (col >= c) continue;
            if (row >= r) continue;
            // printf("[%d ~ %d] -> [%d %d]\n", pos.first, pos.second, row, col);

            bool succes = true;
            for (int j = pos.first; j <= row; j++) {
                if (matrix[j][col] == 0) {
                    succes = false;
                    break;
                }
            }
            if (!succes) continue;

            for (int j = pos.second; j <= col; j++) {
                if (matrix[row][j] == 0) {
                    succes = false;
                    break;
                }
            }
            if (!succes) continue;
            // printf(" - %d, %d\n", pos.first, pos.second);
            table[i - 1].push_back({pos.first, pos.second});
        }

        // dbg(table.back());
    }

    int res = 0;
    for (auto& i : table) res += i.size();
    return res;
}
int main() {
    vector<vector<int>> x{{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
    dbg(countSquares(x));
}

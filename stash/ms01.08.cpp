#include <vector>
using namespace std;
#include "dbg.h"
void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return;
    int row = matrix.size();
    int col = matrix[0].size();

    std::vector<int> row_mark(row, 0);
    std::vector<int> col_mark(col, 0);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                row_mark[i] = 1;
                col_mark[j] = 1;
            }
        }
    }

    dbg(row_mark);
    dbg(col_mark);
    for (int i = 0; i < row; i++) {
        if (row_mark[i] == 1) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < col; i++) {
        if (col_mark[i] == 1) {
            for (int j = 0; j < row; j++) {
                matrix[j][i] = 0;
            }
        }
    }
}

int main() {
    std::vector<std::vector<int>> v = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(v);
    dbg(v);
}
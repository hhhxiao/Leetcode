#include <fstream>
#include <iostream>
#include <vector>

auto read_matrix(FILE* fp, int row, int col) -> std::vector<std::vector<int>> {
    if (!fp) {
        printf("can not open file\n");
        return {};
    }

    std::vector<std::vector<int>> res(row, std::vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            fscanf(fp, "%d", &res[i][j]);
        }
    }

    return res;
}
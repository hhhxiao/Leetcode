#include <fstream>
#include <iostream>
#include <vector>

template <typename T>
auto read_matrix(const std::string& name, int row, int col) -> std::vector<std::vector<T>> {
    std::fstream f(name);

    if (!f.is_open()) {
        printf("can not open file\n");
        return {};
    }

    std::vector<std::vector<T>> res(row, std::vector<T>(col, T{}));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            f >> res[i][j];
        }
    }

    return res;
}
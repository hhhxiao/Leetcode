#include <iostream>
#include <vector>

template <typename T>
void print_matrix(const std::vector<std::vector<T>>& v) {
    if (v.empty() || v[0].empty()) {
        printf("[ size = (0, 0)\n]\n");
    }

    printf("[ size = (%d, %d)\n", v.size(), v[0].size());
    for (auto& row : v) {
        for (auto& e : row) {
            std::cout << "  " << e;
        }
        std::cout << std::endl;
    }
    printf("]\n");
}
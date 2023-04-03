#include <vector>

#include "dbg.h"
#include "io/io.h"
using namespace std;

int dfs(vector<vector<int>>& matrix, vector<vector<int>>& visit, int x, int y) {}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    std::vector<std::vector<int>> visit(matrix.size(), std::vector<int>(matrix[0].size(), 0));
    return dfs(matrix, visit, 0, 0);
}

int main() {
    FILE* fp = fopen("input.txt", "r");
    auto matrix = read_matrix(fp, 3, 3);
    dbg(matrix);
    dbg(longestIncreasingPath(matrix));
    return 0;
}